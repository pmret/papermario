.include "macro.inc"

.section .data

glabel D_E0084E10
.word 0x090018C0, 0x090018C0, 0x090018C0

glabel D_E0084E1C
.word 0x09001D00, 0x09001CC8, 0x09001C80

glabel D_E0084E28
.word 0x090017D0, 0x090017D0, 0x090017D0

glabel D_E0084E34
.word get_model_center_and_size

glabel D_E0084E38
.word get_model_from_list_index

glabel D_E0084E3C
.word get_model_list_index_from_tree_index

glabel D_E0084E40
.double 0.05

glabel D_E0084E48
.double 0.2

glabel D_E0084E50
.double 0.1

glabel D_E0084E58
.double 0.9

glabel D_E0084E60
.double -0.7

glabel D_E0084E68
.double 0.95

glabel D_E0084E70
.double 0.4

glabel D_E0084E78
.double -0.4
