.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C94_E07FF4
/* E07FF4 80242C94 3C06FC12 */  lui       $a2, 0xfc12
/* E07FF8 80242C98 34C64624 */  ori       $a2, $a2, 0x4624
/* E07FFC 80242C9C 3C05FF8F */  lui       $a1, 0xff8f
/* E08000 80242CA0 3C04800A */  lui       $a0, 0x800a
/* E08004 80242CA4 2484A66C */  addiu     $a0, $a0, -0x5994
/* E08008 80242CA8 8C820000 */  lw        $v0, ($a0)
/* E0800C 80242CAC 34A5FFFF */  ori       $a1, $a1, 0xffff
/* E08010 80242CB0 0040182D */  daddu     $v1, $v0, $zero
/* E08014 80242CB4 24420008 */  addiu     $v0, $v0, 8
/* E08018 80242CB8 AC820000 */  sw        $v0, ($a0)
/* E0801C 80242CBC AC660000 */  sw        $a2, ($v1)
/* E08020 80242CC0 AC650004 */  sw        $a1, 4($v1)
/* E08024 80242CC4 24430008 */  addiu     $v1, $v0, 8
/* E08028 80242CC8 AC830000 */  sw        $v1, ($a0)
/* E0802C 80242CCC 3C048024 */  lui       $a0, 0x8024
/* E08030 80242CD0 90845D37 */  lbu       $a0, 0x5d37($a0)
/* E08034 80242CD4 3C03FA00 */  lui       $v1, 0xfa00
/* E08038 80242CD8 AC430000 */  sw        $v1, ($v0)
/* E0803C 80242CDC 03E00008 */  jr        $ra
/* E08040 80242CE0 AC440004 */   sw       $a0, 4($v0)
/* E08044 80242CE4 00000000 */  nop       
/* E08048 80242CE8 00000000 */  nop       
/* E0804C 80242CEC 00000000 */  nop       
