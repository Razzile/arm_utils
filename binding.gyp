{
'targets': [
    {
        'target_name': 'ARM',
        'sources': [
            '/modules/arm_tools/Interface.cc',
            '/modules/arm_tools/ARMDisassembler.cc',
            '/modules/arm_tools/Utils.cc'],

        'cflags': [
            '-std=c++11',
            '-stdlib=libc++'
        ],

        "conditions":
        [
            [ 'OS!="win"', {
                "cflags+": [ "-std=c++11" ],
                "cflags_c+": [ "-std=c++11" ],
                "cflags_cc+": [ "-std=c++11" ],
            }],

            [ 'OS=="mac"', {
                "xcode_settings": {
                    "OTHER_CPLUSPLUSFLAGS" : [ "-std=c++11", "-stdlib=libc++" ],
                    "OTHER_LDFLAGS": [ "-stdlib=libc++" ],
                    "MACOSX_DEPLOYMENT_TARGET": "10.7"
                },
            }]
        ]
    }
]
}
