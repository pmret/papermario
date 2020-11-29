.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802456C8_A2F908
/* A2F908 802456C8 3C06FC12 */  lui       $a2, 0xfc12
/* A2F90C 802456CC 34C61624 */  ori       $a2, $a2, 0x1624
/* A2F910 802456D0 3C05FF2F */  lui       $a1, 0xff2f
/* A2F914 802456D4 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* A2F918 802456D8 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* A2F91C 802456DC 8C820000 */  lw        $v0, ($a0)
/* A2F920 802456E0 34A5FFFF */  ori       $a1, $a1, 0xffff
/* A2F924 802456E4 0040182D */  daddu     $v1, $v0, $zero
/* A2F928 802456E8 24420008 */  addiu     $v0, $v0, 8
/* A2F92C 802456EC AC820000 */  sw        $v0, ($a0)
/* A2F930 802456F0 AC660000 */  sw        $a2, ($v1)
/* A2F934 802456F4 AC650004 */  sw        $a1, 4($v1)
/* A2F938 802456F8 24430008 */  addiu     $v1, $v0, 8
/* A2F93C 802456FC AC830000 */  sw        $v1, ($a0)
/* A2F940 80245700 3C048025 */  lui       $a0, %hi(D_8024DCCF)
/* A2F944 80245704 9084DCCF */  lbu       $a0, %lo(D_8024DCCF)($a0)
/* A2F948 80245708 3C03FA00 */  lui       $v1, 0xfa00
/* A2F94C 8024570C AC430000 */  sw        $v1, ($v0)
/* A2F950 80245710 03E00008 */  jr        $ra
/* A2F954 80245714 AC440004 */   sw       $a0, 4($v0)
