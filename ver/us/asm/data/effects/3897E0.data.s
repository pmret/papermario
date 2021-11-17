.include "macro.inc"

.section .data

dlabel D_E0084E10
.word 0x090018C0, 0x090018C0, 0x090018C0

dlabel D_E0084E1C
.word 0x09001D00, 0x09001CC8, 0x09001C80

dlabel D_E0084E28
.word 0x090017D0, 0x090017D0, 0x090017D0

dlabel D_E0084E34
.word get_model_center_and_size

dlabel D_E0084E38
.word get_model_from_list_index

dlabel D_E0084E3C
.word get_model_list_index_from_tree_index

dlabel D_E0084E40
.double 0.05

dlabel D_E0084E48
.double 0.2

dlabel D_E0084E50
.double 0.1

dlabel D_E0084E58
.double 0.9

dlabel D_E0084E60
.double -0.7

dlabel D_E0084E68
.double 0.95

dlabel D_E0084E70
.double 0.4

dlabel D_E0084E78
.double -0.4
