.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A9E8
/* D10E8 8013A9E8 0000302D */  daddu     $a2, $zero, $zero
/* D10EC 8013A9EC 2402FFFF */  addiu     $v0, $zero, -1
/* D10F0 8013A9F0 A4820010 */  sh        $v0, 0x10($a0)
/* D10F4 8013A9F4 240200FF */  addiu     $v0, $zero, 0xff
/* D10F8 8013A9F8 A0800005 */  sb        $zero, 5($a0)
/* D10FC 8013A9FC A0800006 */  sb        $zero, 6($a0)
/* D1100 8013AA00 AC800014 */  sw        $zero, 0x14($a0)
/* D1104 8013AA04 A0800001 */  sb        $zero, 1($a0)
/* D1108 8013AA08 A0800002 */  sb        $zero, 2($a0)
/* D110C 8013AA0C A4800008 */  sh        $zero, 8($a0)
/* D1110 8013AA10 A480000A */  sh        $zero, 0xa($a0)
/* D1114 8013AA14 A480000C */  sh        $zero, 0xc($a0)
/* D1118 8013AA18 A480000E */  sh        $zero, 0xe($a0)
/* D111C 8013AA1C AC820028 */  sw        $v0, 0x28($a0)
/* D1120 8013AA20 AC820038 */  sw        $v0, 0x38($a0)
/* D1124 8013AA24 A0800003 */  sb        $zero, 3($a0)
/* D1128 8013AA28 A0800004 */  sb        $zero, 4($a0)
/* D112C 8013AA2C A4800008 */  sh        $zero, 8($a0)
/* D1130 8013AA30 A480000A */  sh        $zero, 0xa($a0)
/* D1134 8013AA34 0000182D */  daddu     $v1, $zero, $zero
.L8013AA38:
/* D1138 8013AA38 00062900 */  sll       $a1, $a2, 4
.L8013AA3C:
/* D113C 8013AA3C 00851021 */  addu      $v0, $a0, $a1
/* D1140 8013AA40 AC40001C */  sw        $zero, 0x1c($v0)
/* D1144 8013AA44 24630001 */  addiu     $v1, $v1, 1
/* D1148 8013AA48 28620004 */  slti      $v0, $v1, 4
/* D114C 8013AA4C 1440FFFB */  bnez      $v0, .L8013AA3C
/* D1150 8013AA50 24A50004 */   addiu    $a1, $a1, 4
/* D1154 8013AA54 24C60001 */  addiu     $a2, $a2, 1
/* D1158 8013AA58 28C20002 */  slti      $v0, $a2, 2
/* D115C 8013AA5C 1440FFF6 */  bnez      $v0, .L8013AA38
/* D1160 8013AA60 0000182D */   daddu    $v1, $zero, $zero
/* D1164 8013AA64 0000302D */  daddu     $a2, $zero, $zero
.L8013AA68:
/* D1168 8013AA68 00062900 */  sll       $a1, $a2, 4
.L8013AA6C:
/* D116C 8013AA6C 00851021 */  addu      $v0, $a0, $a1
/* D1170 8013AA70 AC40003C */  sw        $zero, 0x3c($v0)
/* D1174 8013AA74 24630001 */  addiu     $v1, $v1, 1
/* D1178 8013AA78 28620004 */  slti      $v0, $v1, 4
/* D117C 8013AA7C 1440FFFB */  bnez      $v0, .L8013AA6C
/* D1180 8013AA80 24A50004 */   addiu    $a1, $a1, 4
/* D1184 8013AA84 24C60001 */  addiu     $a2, $a2, 1
/* D1188 8013AA88 28C20002 */  slti      $v0, $a2, 2
/* D118C 8013AA8C 1440FFF6 */  bnez      $v0, .L8013AA68
/* D1190 8013AA90 0000182D */   daddu    $v1, $zero, $zero
/* D1194 8013AA94 03E00008 */  jr        $ra
/* D1198 8013AA98 00000000 */   nop
