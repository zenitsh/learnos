SECTIONS{
	. = 0x80200000;
	.text : {*(.entry) *(.text)}
	. = ALIGN(4K);
	.data : {*(.data)}
	.bss : {*(.bss)}
	. = 0x80400000;
	.stack : {*(.stack)}
}
