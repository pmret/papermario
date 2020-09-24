.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel setup_demo_player
/* 4E12C 80072D2C 24030001 */  addiu     $v1, $zero, 1
/* 4E130 80072D30 0060382D */  daddu     $a3, $v1, $zero
/* 4E134 80072D34 24060002 */  addiu     $a2, $zero, 2
/* 4E138 80072D38 3C058011 */  lui       $a1, 0x8011
/* 4E13C 80072D3C 24A5F290 */  addiu     $a1, $a1, -0xd70
/* 4E140 80072D40 24A40008 */  addiu     $a0, $a1, 8
/* 4E144 80072D44 2402000F */  addiu     $v0, $zero, 0xf
/* 4E148 80072D48 A0A20002 */  sb        $v0, 2($a1)
/* 4E14C 80072D4C A0A20003 */  sb        $v0, 3($a1)
/* 4E150 80072D50 A0A20004 */  sb        $v0, 4($a1)
/* 4E154 80072D54 2402000A */  addiu     $v0, $zero, 0xa
/* 4E158 80072D58 A0A20005 */  sb        $v0, 5($a1)
/* 4E15C 80072D5C A0A20006 */  sb        $v0, 6($a1)
/* 4E160 80072D60 A0A20007 */  sb        $v0, 7($a1)
/* 4E164 80072D64 24020003 */  addiu     $v0, $zero, 3
/* 4E168 80072D68 A0A20009 */  sb        $v0, 9($a1)
/* 4E16C 80072D6C 0060102D */  daddu     $v0, $v1, $zero
/* 4E170 80072D70 A0A2000A */  sb        $v0, 0xa($a1)
/* 4E174 80072D74 24020037 */  addiu     $v0, $zero, 0x37
/* 4E178 80072D78 A0A20010 */  sb        $v0, 0x10($a1)
/* 4E17C 80072D7C 24020022 */  addiu     $v0, $zero, 0x22
/* 4E180 80072D80 A0A00000 */  sb        $zero, ($a1)
/* 4E184 80072D84 A0A00001 */  sb        $zero, 1($a1)
/* 4E188 80072D88 A4A2000C */  sh        $v0, 0xc($a1)
.L80072D8C:
/* 4E18C 80072D8C A0870014 */  sb        $a3, 0x14($a0)
/* 4E190 80072D90 A0860015 */  sb        $a2, 0x15($a0)
/* 4E194 80072D94 24630001 */  addiu     $v1, $v1, 1
/* 4E198 80072D98 2862000C */  slti      $v0, $v1, 0xc
/* 4E19C 80072D9C 1440FFFB */  bnez      $v0, .L80072D8C
/* 4E1A0 80072DA0 24840008 */   addiu    $a0, $a0, 8
/* 4E1A4 80072DA4 24020001 */  addiu     $v0, $zero, 1
/* 4E1A8 80072DA8 A0A20012 */  sb        $v0, 0x12($a1)
/* 4E1AC 80072DAC 2403007F */  addiu     $v1, $zero, 0x7f
/* 4E1B0 80072DB0 24A200FE */  addiu     $v0, $a1, 0xfe
.L80072DB4:
/* 4E1B4 80072DB4 A44000B4 */  sh        $zero, 0xb4($v0)
/* 4E1B8 80072DB8 2463FFFF */  addiu     $v1, $v1, -1
/* 4E1BC 80072DBC 0461FFFD */  bgez      $v1, .L80072DB4
/* 4E1C0 80072DC0 2442FFFE */   addiu    $v0, $v0, -2
/* 4E1C4 80072DC4 2403003F */  addiu     $v1, $zero, 0x3f
/* 4E1C8 80072DC8 24A2007E */  addiu     $v0, $a1, 0x7e
.L80072DCC:
/* 4E1CC 80072DCC A4400208 */  sh        $zero, 0x208($v0)
/* 4E1D0 80072DD0 2463FFFF */  addiu     $v1, $v1, -1
/* 4E1D4 80072DD4 0461FFFD */  bgez      $v1, .L80072DCC
/* 4E1D8 80072DD8 2442FFFE */   addiu    $v0, $v0, -2
/* 4E1DC 80072DDC 24030009 */  addiu     $v1, $zero, 9
/* 4E1E0 80072DE0 24A20012 */  addiu     $v0, $a1, 0x12
.L80072DE4:
/* 4E1E4 80072DE4 A44001B4 */  sh        $zero, 0x1b4($v0)
/* 4E1E8 80072DE8 2463FFFF */  addiu     $v1, $v1, -1
/* 4E1EC 80072DEC 0461FFFD */  bgez      $v1, .L80072DE4
/* 4E1F0 80072DF0 2442FFFE */   addiu    $v0, $v0, -2
/* 4E1F4 80072DF4 A0A00288 */  sb        $zero, 0x288($a1)
/* 4E1F8 80072DF8 A0A00289 */  sb        $zero, 0x289($a1)
/* 4E1FC 80072DFC A0A0028A */  sb        $zero, 0x28a($a1)
/* 4E200 80072E00 A4A0028C */  sh        $zero, 0x28c($a1)
/* 4E204 80072E04 A0A0028E */  sb        $zero, 0x28e($a1)
/* 4E208 80072E08 A4A00290 */  sh        $zero, 0x290($a1)
/* 4E20C 80072E0C 03E00008 */  jr        $ra
/* 4E210 80072E10 A0A00292 */   sb       $zero, 0x292($a1)
