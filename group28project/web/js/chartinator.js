/**
 * Chartinator
 * Version: 0.3.8
 * URL: http://chartinator.com
 * Description: Chartinator transforms data contained in HTML tables, Google Sheets and js arrays into charts using Google Charts
 * Requires: jQuery, Google Charts
 * Author: jbowyers
 * Copyright: 2014-2015 jbowyers
 * License: This file is part of Chartinator.
 * Chartinator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Chartinator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/
 *
 * ABOUT CHARTINATOR  ===========================================================================
 * Chartinator transforms data contained in HTML tables, Google Sheets and js arrays into charts using Google Charts.
 *
 * Apply the jQuery Chartinator plugin to the chart canvas(es)
 * or select the table(s) and Chartinator will insert a new chart canvas(es) after the table
 * or define the Google Sheet key id
 * or create js data arrays
 *
 * The header cells (th elements) in HTML table must be in the first row (or first column if transposing table)
 * and should have one of the following:
 * 'data-type' attributes: 'string' 'number' 'boolean' 'date' 'datetime' 'timeofday'
 * or 'data-role' attributes:  'tooltip','annotation'
 * The caption element's text is used as a title for the chart
 * See the readme file for more info
 */

; (function ($, window, document, Math, undefined) {

    'use strict';

    var chartinator = function (el, options) {
        
        //  The chartinator object
        var o = this;

        //  Define table and chart elements	
        var $tableS = $(el);
        var $chartS = $tableS;

        //  Define fonts
        o.fontFamily = $('body').css('font-family').replace(/["']{1}/gi, "") || 'Arial, Helvetica, sans-serif';

        //  Initialize option defaults ------------------------------------------------------------
        o.optionsInit = {

            // The path to the Google AJAX API
            urlJSAPI: 'https://www.google.com/jsapi',

            // The Google Sheet key
            // The id code of the Google sheet taken from the public url of your Google Sheet
            // Default: false
            googleSheetKey: false,

            // The data columns js array
            // An array of object literals that define each column
            // Default: false
            columns: false,

            // Column indexes array - An array of column indexes defining where
            // the data will be inserted into any existing data extracted from an HTML table or Google Sheet
            // Default: false - js data array columns replace any existing columns
            // Note: when inserting more than one column be sure to increment index number
            // to account for previously inserted indexes
            colIndexes: false,

            // Rows - The rows data-array
            // If colIndexes array has values the row data will be inserted into the columns
            // defined in the colindexes array. Otherwise the row data will be appended
            // to any existing row data extracted from an HTML table or Google Sheet
            // Default: false
            rows: false,

            // The jQuery selector of the HTML table element to extract the data from.
            // Default: false - Checks if the element this plugin is applied to is an HTML table
            tableSel: false,

            // The data title
            // A title used to identify the set of data
            // Used as a caption when generating an HTML table
            dataTitle: false,

            // Create Table
            // Create an HTML table from chart data
            // Note: This table will replace an existing HTML table
            createTable: false,

            // Ignore row indexes array - An array of row index numbers to ignore
            // Default: []
            // Note: Only works on data extracted from HTML tables or Google Sheets
            // The headings row is index 0
            ignoreRow: [],

            // Ignore column indexes array
            // An array of column indexes to ignore in the HTML table or Google Sheet
            // Default: []
            // Note: Only works on data extracted from HTML tables or Google Sheets
            ignoreCol: [],

            // Transpose data Boolean - swap columns and rows
            // Default: false
            // Note: Only works on data extracted from HTML tables or Google Sheets
            transpose: false,

            // The tooltip concatenation - Defines a string for concatenating a custom tooltip.
            // Keywords: 'domain', 'data', 'label' - these will be replaced with current values
            // 'domain': the primary axis value, 'data': the data value, 'label': the column title
            // Default: false - use Google Charts tooltip defaults
            // Note: Only works when extracting data from HTML tables or Google Sheets
            // Not supported on pie, calendar charts
            tooltipConcat: false,

            // The annotation concatenation - Defines a string for concatenating a custom annotation.
            // Keywords: 'domain', 'data', 'label' - these will be replaced with current values
            // 'domain': the primary axis value, 'data': the data value, 'label': the column title
            // Default: false - use Google Charts annotation defaults
            // Note: Only works when extracting data from HTML tables or Google Sheets.
            // Not supported on pie, geo, calendar charts
            annotationConcat: false,

            // The chart type - String
            // Derived from the Google Charts visualization class name
            // Default: 'BarChart'
            // Use TitleCase names. eg. BarChart, PieChart, ColumnChart, Calendar, GeoChart, Table.
            // See Google Charts Gallery for a complete list of Chart types
            // https://developers.google.com/chart/interactive/docs/gallery
            chartType: 'BarChart',

            // Chart Id - The id applied to the chart container element as an id and a class
            // This is overridden if the chart element has an id or is user defined
            chartId: 'c24_chart_' + Math.random().toString(36).substr(2, 9),

            // The class to apply to the chart container element
            chartClass: 'chtr-chart',

            // Table Id - The id applied to the table element as an id and a class
            // This is overridden if the table element has an id or is user defined
            tableId: 'c24_table_' + Math.random().toString(36).substr(2, 9),

            // The class to apply to the table element
            tableClass: 'chtr-table',

            // The chart aspect ratio custom option - width/height
            // Used to calculate the chart dimensions relative to the width or height
            // this is overridden if the Google Chart's height and width options have values
            // Default: false - not used
            chartAspectRatio: false,

            // The chart zoom factor - number
            // A scaling factor for the chart - uses CSS3 transform
            // To prevent tooltips from displaying off canvas while zooming, set tooltip.isHtml: true
            // Default: 0
            chartZoom: 0,

            // The chart offset - Array of numbers
            // An array of x and y offset percentage values
            // Used to offset the chart by percentages of the height and width - uses CSS3 transform
            // To prevent tooltips from displaying off canvas while offsetting, set tooltip.isHtml: true
            // Default: false
            chartOffset: false,

            // Google Bar Chart Default Options
            barChart: {

                // The font size in pixels - Number
                // Or use css selectors as keywords to assign font sizes from the page
                // For example: 'body'
                // Default: false - Use Google Charts defaults
                fontSize: false,

                // the body font-family
                fontName: o.fontFamily,

                chartArea: { left: '20%', top: 40, width: '75%', height: '85%' },

                legend: { position: 'bottom' }
            },

            // Google Pie Chart Default Options
            pieChart: {

                // The font size in pixels - Number
                // Or use css selectors as keywords to assign font sizes from the page
                // For example: 'body'
                // Default: false - Use Google Charts defaults
                fontSize: false,

                // the body font-family
                fontName: o.fontFamily,

                chartArea: { left: '6%', top: 40, width: '94%', height: '100%' }
            },

            // Google Column Chart Default Options
            columnChart: {

                // The font size in pixels - Number
                // Or use css selectors as keywords to assign font sizes from the page
                // For example: 'body'
                // Default: false - Use Google Charts defaults
                fontSize: false,

                // the body font-family
                fontName: o.fontFamily,

                chartArea: { left: '15%', top: 40, width: '85%', height: '70%' },

                legend: { position: 'bottom' }
            },

            // Google line Chart Default Options
            lineChart: {

                // The font size in pixels - Number
                // Or use css selectors as keywords to assign font sizes from the page
                // For example: 'body'
                // Default: false - Use Google Charts defaults
                fontSize: false,

                // the body font-family
                fontName: o.fontFamily,

                chartArea: { left: '15%', top: 40, width: '80%', height: '70%' },

                legend: { position: 'bottom' }
            },

            // Google Area Chart Default Options
            areaChart: {

                // The font size in pixels - Number
                // Or use css selectors as keywords to assign font sizes from the page
                // For example: 'body'
                // Default: false - Use Google Charts defaults
                fontSize: false,

                // the body font-family
                fontName: o.fontFamily,

                chartArea: { left: '15%', top: 40, width: '80%', height: '70%' },

                legend: { position: 'bottom' }
            },

            // Google Calendar Chart Default Options
            calendar: {

                // The cell scaling factor custom option - Not a Google Chart option
                // Used to refactor the cell size in responsive designs
                // this is overridden if the calendar.cellSize option has a value
                cellScaleFactor: 0.017,

                titleTextStyle: {
                    // Note: Support for this option has been added by Chartinator
                    // but is not supported by Google Charts for this chart type

                    color: '#000',
                    fontWeight: 'bold',
                    fontName: o.fontFamily,

                    // The font size in pixels - Number
                    // Or use css selectors as keywords to assign font sizes from the page
                    // For example: 'body'
                    // Default: false - Use Google Charts defaults
                    fontSize: 'h3'
                },

                calendar: {
                    monthLabel: {

                        // The font size in pixels - Number
                        // Or use css selectors as keywords to assign font sizes from the page
                        // For example: 'body'
                        // Default: false - Use Google Charts defaults
                        fontSize: false,

                        fontName: o.fontFamily
                    },
                    dayOfWeekLabel: {

                        // The font size in pixels - Number
                        // Or use css selectors as keywords to assign font sizes from the page
                        // For example: 'body'
                        // Default: false - Use Google Charts defaults
                        fontSize: false,

                        fontName: o.fontFamily
                    }
                },
                tooltip: {

                    // Note: Support for this option has been added by Chartinator
                    // but is not supported by Google Charts for this chart type
                    textStyle: {
                        color: '#000',
                        fontName: o.fontFamily,
                        fontSize: 16
                    }
                }
            },

            // Google Table Chart Default Options
            table: {

                // Format a data column in a Table Chart
                formatter: {

                    // Formatter type - Options: 'none', 'BarFormat'
                    type: 'none',

                    // The index number of the column to format. Options: 0, 1, 2, etc.
                    column: 1
                },

                // Allow HTML in cells. default: false
                allowHtml: true,

                cssClassNames: {
                    headerRow: 'headerRow',
                    tableRow: 'tableRow',
                    oddTableRow: 'oddTableRow',
                    selectedTableRow: 'selectedTableRow',
                    hoverTableRow: 'hoverTableRow',
                    headerCell: 'headerCell',
                    tableCell: 'tableCell',
                    rowNumberCell: 'rowNumberCell'
                }
            },

            // Show table along with chart. String, Options: 'show', 'hide', 'remove'
            showTable: 'hide',

            // The CSS to apply to show or hide the table and chart
            showTableCSS: { 'position': 'static', 'top': 0, 'width': '' },
            hideTableCSS: { 'position': 'absolute', 'top': '-99999px', 'width': $tableS.width() },
            showChartCSS: {  },
            hideChartCSS: { 'opacity': 0 }

        };  //  o.optionsInit close

        // The Google Chart options object
        o.chartOptions = {};

        // The Google Chart options object clone
        o.cchartOptions = {};

        // Window resize event timer function
        o.timer = false;

        // Chart Id - The id to apply to the chart container element
        o.chartId = o.optionsInit.chartId;

        // Table Id - The id to apply to the table element
        o.tableId = o.optionsInit.tableId;

        // The table has data boolean
        o.tableHasData = false;

        o.tableCaption = false;

        // The Google Sheet data object - Data returned
        o.googleSheetData = false;

        // Data array - the array of collected data to send to Google Charts
        o.dataArray = [];

        // Set chartPackage - Default: corechart - The Google Chart Package to load.
        o.chartPackage = 'corechart';

        // Array of chart types included in the Google Charts corechart package
        o.coreCharts = ['BarChart','ColumnChart','PieChart','AreaChart','BubbleChart','CandlestickChart','ComboChart','Histogram', 'LineChart', 'ScatterChart', 'SteppedAreaChart'];

        // Init chart parent
        o.chartParent = false;

        // Init the window width
        o.windowWidth = false;

        // Init chart parent width
        o.chartParentWidth = false;

        //  Initiate Chart ======================================================================
        o.init = function (el, options) {

            //  Merge options
            o.options = $.extend( true, {}, o.optionsInit, options );

            // Update chartId
            o.chartId = options.chartId || $chartS.attr('id') || o.options.chartId ;

            // Define table and chart elements --------------------------------------------------

            // Set table element
            if (o.options.tableSel) {
                $tableS = ($(o.options.tableSel + ' td').length) ? $(o.options.tableSel) : $tableS;
            }

            // Check table for data
            o.tableHasData = $tableS.find('td').length;

            if ($chartS[0] === $tableS[0]) { // table and chart are the same element

                if (o.tableHasData) { // chart element does not exist

                    // Reset Chart id
                    o.chartId = o.options.chartId ;

                    // Insert a new chart element after the table
                    $chartS = $( '<div id="' + o.chartId +
                        '" class="' + o.chartId + ' ' + o.options.chartClass +
                        '"></div>' ).insertAfter( $tableS );

                } else { // table does not exist
                    $tableS = false;
                }
            }

            // Add chart class and id
            $chartS
                .addClass( o.chartId + ' ' + o.options.chartClass )
                .attr( 'id', o.chartId );

            // Add table class and id and get caption
            if (o.tableHasData) {

                // Update tableId
                o.tableId = options.tableId || $tableS.attr('id') || o.options.tableId ;

                // Apply id and classes to table
                $tableS
                    .addClass( o.tableId + ' ' + o.options.tableClass )
                    .attr( 'id', o.tableId );

                o.tableCaption = $tableS.find( 'caption' );

            } else {

                // Update tableId
                o.tableId = o.options.tableId ;
            }

            // Get chart parent element
            o.chartParent = $chartS.parent();

            // Get data ----------------------------------------------------------
            if ( o.options.googleSheetKey ) {

                // Get Google Sheets data
                o.getGoogleSheet( o.options.googleSheetKey, o.setupChart );
            } else {
                o.setupChart();
            }

        };  // o.init close

        // Get Google Sheet data - CSV format
        o.getGoogleSheet = function ( key, callBack ) {

            $.ajax({
                type: 'GET',
                url: 'https://spreadsheets.google.com/spreadsheet/pub?key=' + key + '&output=csv',
                dataType: 'text'
            })
                .done(function (data) {
                    o.googleSheetData = data;
                    callBack();
                })
                .fail(function (e) {
                    o.googleSheetData = e;
                    callBack();
                    // Google Sheet failed
                    console.log('Google Sheet failed');
                })
            ;
        };

        // Set the chart - get Google Chart
        o.setupChart = function ( ) {

            // Get data
            o.dataArray = o.collectData();

            if ( !o.dataArray.length ) { // No data

                // Show table remove chart
                o.showTableChart('show', 'remove');
                console.log('No data found in data array');
                return;
            }

            // Set chart package
            if ( o.coreCharts.indexOf(o.options.chartType) === -1 ) { // not a core chart

                // Get chart package from chart type
                o.chartPackage = o.options.chartType.toLowerCase();
            }

            // Construct Chart options -------------------------------------------

            // Set the Google chart options
            if ( o.options.chartOptions ) { // Use chartOptions object if it exists
                o.chartOptions = o.options.chartOptions;
            } else if (o.options[o.camelCase(o.options.chartType)]) { // Use options specific to the chart type if they exist
                o.chartOptions = o.options[o.camelCase(o.options.chartType)];
            }

            // Clone Google Chart options so we don't overwrite original values
            o.cchartOptions = $.extend( true, {}, o.chartOptions );

            // Create table -------------------------------------------------------
            if ( o.options.createTable ) {

                // The caption text
                var tableTitle = o.options.dataTitle || o.cchartOptions.title || 'The Chart Data';

                if ( o.tableHasData ) {
                    $tableS.replaceWith( o.generateTable( o.dataArray, tableTitle, o.tableId, o.options.tableClass ) );
                } else {
                    $tableS = o.generateTable( o.dataArray, tableTitle, o.tableId, o.options.tableClass ).insertBefore( $chartS );
                }
            } else if ( o.tableHasData && o.options.dataTitle ) {
                o.tableCaption.text( o.options.dataTitle );
            }

            // Load Google Chart --------------------------------------------------

            // Hide chart and HTML table
            o.showTableChart('hide', 'hide');

            try {

                $.ajax({
                    url: o.options.urlJSAPI,
                    dataType: 'script',
                    cache: true
                })
                    .done(function () {

                        // Create and draw Chart
                        google.load('visualization', '1', {
                            packages: [o.chartPackage],
                            callback: o.drawChart
                        });

                        // Add Window Resize event
                        o.addResize();
                    })
                    .fail(function () {

                        // Chart failed - Show HTML table and remove chart
                        o.showTableChart('show', 'remove');
                    })
                ;
            }
            catch (e) {

                // Chart failed - Show HTML table and remove chart
                o.showTableChart('show', 'remove');
                console.log(e);
            }

        };

        // Collect data - Assemble data from the HTML table, js array and Google Sheet
        // Returns an Array of data
        o.collectData = function () {

            var dataArray = [];

            // Format Google Sheet data
            if ( o.googleSheetData && !o.googleSheetData.statusText ) {
                dataArray = o.formatSheet( o.googleSheetData );
            } else if ( o.googleSheetData ) {
                console.log(o.googleSheetData);
            }

            // Get HTML table data
            // Note: this overwrites any data extracted from A Google Sheet
            if ( o.tableHasData ) {
                dataArray = o.getTableData( $tableS );
            }

            // Add/overwrite with js data-array columns
            if ( o.options.columns ) {
                if (dataArray[0] && dataArray[0][0] && dataArray[0][0].label) { // header data exists
                    if ( o.options.colIndexes ) { // insert columns
                        for (var i = 0; i < o.options.colIndexes.length; i++) {
                            dataArray[0].splice(o.options.colIndexes[i], 0, o.options.columns[i]);
                        }
                    } else {
                        // Overwrite columns array as first row
                        dataArray[0] = o.options.columns;
                    }
                } else { // header data does not exists
                    // Insert columns array as first row
                    dataArray.unshift(o.options.columns);
                }
            }

            // Add js data-array rows
            if (  o.options.rows && dataArray.length ) { // js data array exists
                if ( o.options.colIndexes ) { // colIndexes array exists
                    for (var i = 0; i < o.options.rows.length; i++) { // loop through each row in js data array
                        for (var j=0; j < o.options.colIndexes.length; j++) { // loop through colIndexes

                            // Insert new data into dataArray
                            dataArray[i+1].splice(o.options.colIndexes[j],