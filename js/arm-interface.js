var ARM = require('./build/Release/ARM.node');

window.onload = function() {
    console.log(ARM.decodeARM("0xE3A000FF"));
};
