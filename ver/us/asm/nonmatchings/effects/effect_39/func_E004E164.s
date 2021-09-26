.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004E164
/* 35BB34 E004E164 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 35BB38 E004E168 0080282D */  daddu     $a1, $a0, $zero
/* 35BB3C E004E16C AFBF0010 */  sw        $ra, 0x10($sp)
/* 35BB40 E004E170 8CA2000C */  lw        $v0, 0xc($a1)
/* 35BB44 E004E174 3C014100 */  lui       $at, 0x4100
/* 35BB48 E004E178 44810000 */  mtc1      $at, $f0
/* 35BB4C E004E17C 8C430018 */  lw        $v1, 0x18($v0)
/* 35BB50 E004E180 8C440014 */  lw        $a0, 0x14($v0)
/* 35BB54 E004E184 44831000 */  mtc1      $v1, $f2
/* 35BB58 E004E188 00000000 */  nop
/* 35BB5C E004E18C 468010A0 */  cvt.s.w   $f2, $f2
/* 35BB60 E004E190 24630001 */  addiu     $v1, $v1, 1
/* 35BB64 E004E194 46001082 */  mul.s     $f2, $f2, $f0
/* 35BB68 E004E198 00000000 */  nop
/* 35BB6C E004E19C 2484FFFF */  addiu     $a0, $a0, -1
/* 35BB70 E004E1A0 C440001C */  lwc1      $f0, 0x1c($v0)
/* 35BB74 E004E1A4 46800020 */  cvt.s.w   $f0, $f0
/* 35BB78 E004E1A8 AC430018 */  sw        $v1, 0x18($v0)
/* 35BB7C E004E1AC AC440014 */  sw        $a0, 0x14($v0)
/* 35BB80 E004E1B0 46001083 */  div.s     $f2, $f2, $f0
/* 35BB84 E004E1B4 04810003 */  bgez      $a0, .LE004E1C4
/* 35BB88 E004E1B8 E4420020 */   swc1     $f2, 0x20($v0)
/* 35BB8C E004E1BC 0C080128 */  jal       shim_remove_effect
/* 35BB90 E004E1C0 00A0202D */   daddu    $a0, $a1, $zero
.LE004E1C4:
/* 35BB94 E004E1C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 35BB98 E004E1C8 03E00008 */  jr        $ra
/* 35BB9C E004E1CC 27BD0018 */   addiu    $sp, $sp, 0x18
