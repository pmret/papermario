.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BB8_A11438
/* A11438 80240BB8 3C06FC12 */  lui       $a2, 0xfc12
/* A1143C 80240BBC 34C61624 */  ori       $a2, $a2, 0x1624
/* A11440 80240BC0 3C05FF2F */  lui       $a1, 0xff2f
/* A11444 80240BC4 3C04800A */  lui       $a0, 0x800a
/* A11448 80240BC8 2484A66C */  addiu     $a0, $a0, -0x5994
/* A1144C 80240BCC 8C820000 */  lw        $v0, ($a0)
/* A11450 80240BD0 34A5FFFF */  ori       $a1, $a1, 0xffff
/* A11454 80240BD4 0040182D */  daddu     $v1, $v0, $zero
/* A11458 80240BD8 24420008 */  addiu     $v0, $v0, 8
/* A1145C 80240BDC AC820000 */  sw        $v0, ($a0)
/* A11460 80240BE0 AC660000 */  sw        $a2, ($v1)
/* A11464 80240BE4 AC650004 */  sw        $a1, 4($v1)
/* A11468 80240BE8 24430008 */  addiu     $v1, $v0, 8
/* A1146C 80240BEC AC830000 */  sw        $v1, ($a0)
/* A11470 80240BF0 3C048024 */  lui       $a0, 0x8024
/* A11474 80240BF4 90841C2F */  lbu       $a0, 0x1c2f($a0)
/* A11478 80240BF8 3C03FA00 */  lui       $v1, 0xfa00
/* A1147C 80240BFC AC430000 */  sw        $v1, ($v0)
/* A11480 80240C00 03E00008 */  jr        $ra
/* A11484 80240C04 AC440004 */   sw       $a0, 4($v0)
