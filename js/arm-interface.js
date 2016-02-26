var ARM = require('./build/Release/ARM.node');


function convert(frm) {

    var result = ARM.decodeARM(frm.hex.value);

    var tableRef = document.getElementById('resultsTable').getElementsByTagName('tbody')[0];
    var newRow   = tableRef.insertRow(tableRef.rows.length);

    var arm  = newRow.insertCell(0);
    var mode = newRow.insertCell(1);
    var hex  = newRow.insertCell(2);

    var armtext  = document.createTextNode(result);
    var modetext = document.createTextNode("ARM");
    var hextext  = document.createTextNode(frm.hex.value);

    arm.appendChild(armtext);
    mode.appendChild(modetext);
    hex.appendChild(hextext);
}
