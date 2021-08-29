.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218280_6609D0
/* 6609D0 80218280 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6609D4 80218284 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6609D8 80218288 8C82000C */  lw        $v0, 0xc($a0)
/* 6609DC 8021828C 0C0B1EAF */  jal       evt_get_variable
/* 6609E0 80218290 8C450000 */   lw       $a1, ($v0)
/* 6609E4 80218294 8C43000C */  lw        $v1, 0xc($v0)
/* 6609E8 80218298 240400F8 */  addiu     $a0, $zero, 0xf8
/* 6609EC 8021829C AC640018 */  sw        $a0, 0x18($v1)
/* 6609F0 802182A0 8C43000C */  lw        $v1, 0xc($v0)
/* 6609F4 802182A4 AC64001C */  sw        $a0, 0x1c($v1)
/* 6609F8 802182A8 8C43000C */  lw        $v1, 0xc($v0)
/* 6609FC 802182AC 240500FF */  addiu     $a1, $zero, 0xff
/* 660A00 802182B0 AC650020 */  sw        $a1, 0x20($v1)
/* 660A04 802182B4 8C44000C */  lw        $a0, 0xc($v0)
/* 660A08 802182B8 24030080 */  addiu     $v1, $zero, 0x80
/* 660A0C 802182BC AC830028 */  sw        $v1, 0x28($a0)
/* 660A10 802182C0 8C44000C */  lw        $a0, 0xc($v0)
/* 660A14 802182C4 240300E0 */  addiu     $v1, $zero, 0xe0
/* 660A18 802182C8 AC83002C */  sw        $v1, 0x2c($a0)
/* 660A1C 802182CC 8C43000C */  lw        $v1, 0xc($v0)
/* 660A20 802182D0 AC650030 */  sw        $a1, 0x30($v1)
/* 660A24 802182D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 660A28 802182D8 24020002 */  addiu     $v0, $zero, 2
/* 660A2C 802182DC 03E00008 */  jr        $ra
/* 660A30 802182E0 27BD0018 */   addiu    $sp, $sp, 0x18
