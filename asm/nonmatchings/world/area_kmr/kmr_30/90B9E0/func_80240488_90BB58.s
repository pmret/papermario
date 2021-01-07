.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240488_90BB58
/* 90BB58 80240488 3C06FC12 */  lui       $a2, 0xfc12
/* 90BB5C 8024048C 34C61624 */  ori       $a2, $a2, 0x1624
/* 90BB60 80240490 3C05FF2F */  lui       $a1, 0xff2f
/* 90BB64 80240494 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 90BB68 80240498 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 90BB6C 8024049C 8C820000 */  lw        $v0, ($a0)
/* 90BB70 802404A0 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 90BB74 802404A4 0040182D */  daddu     $v1, $v0, $zero
/* 90BB78 802404A8 24420008 */  addiu     $v0, $v0, 8
/* 90BB7C 802404AC AC820000 */  sw        $v0, ($a0)
/* 90BB80 802404B0 AC660000 */  sw        $a2, ($v1)
/* 90BB84 802404B4 AC650004 */  sw        $a1, 4($v1)
/* 90BB88 802404B8 24430008 */  addiu     $v1, $v0, 8
/* 90BB8C 802404BC AC830000 */  sw        $v1, ($a0)
/* 90BB90 802404C0 3C048024 */  lui       $a0, %hi(D_80240C0F)
/* 90BB94 802404C4 90840C0F */  lbu       $a0, %lo(D_80240C0F)($a0)
/* 90BB98 802404C8 3C03FA00 */  lui       $v1, 0xfa00
/* 90BB9C 802404CC AC430000 */  sw        $v1, ($v0)
/* 90BBA0 802404D0 03E00008 */  jr        $ra
/* 90BBA4 802404D4 AC440004 */   sw       $a0, 4($v0)
/* 90BBA8 802404D8 00000000 */  nop       
/* 90BBAC 802404DC 00000000 */  nop       
