.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241384
/* A9A914 80241384 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A9A918 80241388 3C05FE36 */  lui       $a1, 0xfe36
/* A9A91C 8024138C AFBF0010 */  sw        $ra, 0x10($sp)
/* A9A920 80241390 8C820148 */  lw        $v0, 0x148($a0)
/* A9A924 80241394 3C06800B */  lui       $a2, 0x800b
/* A9A928 80241398 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* A9A92C 8024139C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A9A930 802413A0 00C23026 */  xor       $a2, $a2, $v0
/* A9A934 802413A4 0C0B2026 */  jal       set_variable
/* A9A938 802413A8 2CC60001 */   sltiu    $a2, $a2, 1
/* A9A93C 802413AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A9A940 802413B0 24020002 */  addiu     $v0, $zero, 2
/* A9A944 802413B4 03E00008 */  jr        $ra
/* A9A948 802413B8 27BD0018 */   addiu    $sp, $sp, 0x18
/* A9A94C 802413BC 00000000 */  nop       
