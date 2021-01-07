.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802454B4_805D34
/* 805D34 802454B4 3C06FCFF */  lui       $a2, 0xfcff
/* 805D38 802454B8 34C6C7FF */  ori       $a2, $a2, 0xc7ff
/* 805D3C 802454BC 3C05FF8F */  lui       $a1, 0xff8f
/* 805D40 802454C0 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* 805D44 802454C4 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* 805D48 802454C8 8C820000 */  lw        $v0, ($a0)
/* 805D4C 802454CC 34A57FBF */  ori       $a1, $a1, 0x7fbf
/* 805D50 802454D0 0040182D */  daddu     $v1, $v0, $zero
/* 805D54 802454D4 24420008 */  addiu     $v0, $v0, 8
/* 805D58 802454D8 AC820000 */  sw        $v0, ($a0)
/* 805D5C 802454DC AC660000 */  sw        $a2, ($v1)
/* 805D60 802454E0 AC650004 */  sw        $a1, 4($v1)
/* 805D64 802454E4 24430008 */  addiu     $v1, $v0, 8
/* 805D68 802454E8 AC830000 */  sw        $v1, ($a0)
/* 805D6C 802454EC 3C048026 */  lui       $a0, %hi(D_80258407)
/* 805D70 802454F0 90848407 */  lbu       $a0, %lo(D_80258407)($a0)
/* 805D74 802454F4 3C03FA00 */  lui       $v1, 0xfa00
/* 805D78 802454F8 AC430000 */  sw        $v1, ($v0)
/* 805D7C 802454FC 03E00008 */  jr        $ra
/* 805D80 80245500 AC440004 */   sw       $a0, 4($v0)
