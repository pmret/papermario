.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044CB0
/* 200B0 80044CB0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 200B4 80044CB4 AFB10014 */  sw        $s1, 0x14($sp)
/* 200B8 80044CB8 0080882D */  daddu     $s1, $a0, $zero
/* 200BC 80044CBC AFBF0020 */  sw        $ra, 0x20($sp)
/* 200C0 80044CC0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 200C4 80044CC4 AFB20018 */  sw        $s2, 0x18($sp)
/* 200C8 80044CC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 200CC 80044CCC 8E30000C */  lw        $s0, 0xc($s1)
/* 200D0 80044CD0 8E330148 */  lw        $s3, 0x148($s1)
/* 200D4 80044CD4 8E050000 */  lw        $a1, ($s0)
/* 200D8 80044CD8 0C0B1EAF */  jal       func_802C7ABC
/* 200DC 80044CDC 26100004 */   addiu    $s0, $s0, 4
/* 200E0 80044CE0 0040902D */  daddu     $s2, $v0, $zero
/* 200E4 80044CE4 8E050000 */  lw        $a1, ($s0)
/* 200E8 80044CE8 0C0B1EAF */  jal       func_802C7ABC
/* 200EC 80044CEC 0220202D */   daddu    $a0, $s1, $zero
/* 200F0 80044CF0 0040802D */  daddu     $s0, $v0, $zero
/* 200F4 80044CF4 2402FFFF */  addiu     $v0, $zero, -1
/* 200F8 80044CF8 16420002 */  bne       $s2, $v0, .L80044D04
/* 200FC 80044CFC 00000000 */   nop
/* 20100 80044D00 86720008 */  lh        $s2, 8($s3)
.L80044D04:
/* 20104 80044D04 0C00FA6A */  jal       func_8003E9A8
/* 20108 80044D08 0240202D */   daddu    $a0, $s2, $zero
/* 2010C 80044D0C 12000008 */  beqz      $s0, .L80044D30
/* 20110 80044D10 0040982D */   daddu    $s3, $v0, $zero
/* 20114 80044D14 8E620044 */  lw        $v0, 0x44($s3)
/* 20118 80044D18 1040000A */  beqz      $v0, .L80044D44
/* 2011C 80044D1C 00000000 */   nop
/* 20120 80044D20 0C0B1123 */  jal       func_802C448C
/* 20124 80044D24 8E64005C */   lw       $a0, 0x5c($s3)
/* 20128 80044D28 08011351 */  j         .L80044D44
/* 2012C 80044D2C 00000000 */   nop
.L80044D30:
/* 20130 80044D30 8E620044 */  lw        $v0, 0x44($s3)
/* 20134 80044D34 10400003 */  beqz      $v0, .L80044D44
/* 20138 80044D38 00000000 */   nop
/* 2013C 80044D3C 0C0B1108 */  jal       func_802C4420
/* 20140 80044D40 8E64005C */   lw       $a0, 0x5c($s3)
.L80044D44:
/* 20144 80044D44 8FBF0020 */  lw        $ra, 0x20($sp)
/* 20148 80044D48 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2014C 80044D4C 8FB20018 */  lw        $s2, 0x18($sp)
/* 20150 80044D50 8FB10014 */  lw        $s1, 0x14($sp)
/* 20154 80044D54 8FB00010 */  lw        $s0, 0x10($sp)
/* 20158 80044D58 24020002 */  addiu     $v0, $zero, 2
/* 2015C 80044D5C 03E00008 */  jr        $ra
/* 20160 80044D60 27BD0028 */   addiu    $sp, $sp, 0x28
