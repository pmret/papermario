.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PlayerMoveTo
/* F5AE4 802D1134 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F5AE8 802D1138 AFB10014 */  sw        $s1, 0x14($sp)
/* F5AEC 802D113C 0080882D */  daddu     $s1, $a0, $zero
/* F5AF0 802D1140 AFB20018 */  sw        $s2, 0x18($sp)
/* F5AF4 802D1144 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* F5AF8 802D1148 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* F5AFC 802D114C AFBF001C */  sw        $ra, 0x1c($sp)
/* F5B00 802D1150 AFB00010 */  sw        $s0, 0x10($sp)
/* F5B04 802D1154 F7B60028 */  sdc1      $f22, 0x28($sp)
/* F5B08 802D1158 F7B40020 */  sdc1      $f20, 0x20($sp)
/* F5B0C 802D115C 10A00038 */  beqz      $a1, .L802D1240
/* F5B10 802D1160 8E30000C */   lw       $s0, 0xc($s1)
/* F5B14 802D1164 8E050000 */  lw        $a1, ($s0)
/* F5B18 802D1168 0C0B1EAF */  jal       get_variable
/* F5B1C 802D116C 26100004 */   addiu    $s0, $s0, 4
/* F5B20 802D1170 8E050000 */  lw        $a1, ($s0)
/* F5B24 802D1174 26100004 */  addiu     $s0, $s0, 4
/* F5B28 802D1178 4482B000 */  mtc1      $v0, $f22
/* F5B2C 802D117C 00000000 */  nop       
/* F5B30 802D1180 4680B5A0 */  cvt.s.w   $f22, $f22
/* F5B34 802D1184 0C0B1EAF */  jal       get_variable
/* F5B38 802D1188 0220202D */   daddu    $a0, $s1, $zero
/* F5B3C 802D118C 8E050000 */  lw        $a1, ($s0)
/* F5B40 802D1190 4482A000 */  mtc1      $v0, $f20
/* F5B44 802D1194 00000000 */  nop       
/* F5B48 802D1198 4680A520 */  cvt.s.w   $f20, $f20
/* F5B4C 802D119C 0C0B1EAF */  jal       get_variable
/* F5B50 802D11A0 0220202D */   daddu    $a0, $s1, $zero
/* F5B54 802D11A4 AE220070 */  sw        $v0, 0x70($s1)
/* F5B58 802D11A8 C64C0028 */  lwc1      $f12, 0x28($s2)
/* F5B5C 802D11AC C64E0030 */  lwc1      $f14, 0x30($s2)
/* F5B60 802D11B0 4406B000 */  mfc1      $a2, $f22
/* F5B64 802D11B4 4407A000 */  mfc1      $a3, $f20
/* F5B68 802D11B8 0C00A720 */  jal       atan2
/* F5B6C 802D11BC 00000000 */   nop      
/* F5B70 802D11C0 E6400080 */  swc1      $f0, 0x80($s2)
/* F5B74 802D11C4 8E220070 */  lw        $v0, 0x70($s1)
/* F5B78 802D11C8 1440000F */  bnez      $v0, .L802D1208
/* F5B7C 802D11CC 00000000 */   nop      
/* F5B80 802D11D0 C64C0028 */  lwc1      $f12, 0x28($s2)
/* F5B84 802D11D4 C64E0030 */  lwc1      $f14, 0x30($s2)
/* F5B88 802D11D8 4406B000 */  mfc1      $a2, $f22
/* F5B8C 802D11DC 4407A000 */  mfc1      $a3, $f20
/* F5B90 802D11E0 0C00A7B5 */  jal       dist2D
/* F5B94 802D11E4 00000000 */   nop      
/* F5B98 802D11E8 3C02802E */  lui       $v0, %hi(gPlayerNpcPtr)
/* F5B9C 802D11EC 8C429D20 */  lw        $v0, %lo(gPlayerNpcPtr)($v0)
/* F5BA0 802D11F0 C4420018 */  lwc1      $f2, 0x18($v0)
/* F5BA4 802D11F4 46020003 */  div.s     $f0, $f0, $f2
/* F5BA8 802D11F8 4600010D */  trunc.w.s $f4, $f0
/* F5BAC 802D11FC E6240070 */  swc1      $f4, 0x70($s1)
/* F5BB0 802D1200 080B448B */  j         .L802D122C
/* F5BB4 802D1204 C4400018 */   lwc1     $f0, 0x18($v0)
.L802D1208:
/* F5BB8 802D1208 C64C0028 */  lwc1      $f12, 0x28($s2)
/* F5BBC 802D120C C64E0030 */  lwc1      $f14, 0x30($s2)
/* F5BC0 802D1210 4406B000 */  mfc1      $a2, $f22
/* F5BC4 802D1214 4407A000 */  mfc1      $a3, $f20
/* F5BC8 802D1218 0C00A7B5 */  jal       dist2D
/* F5BCC 802D121C 00000000 */   nop      
/* F5BD0 802D1220 C6220070 */  lwc1      $f2, 0x70($s1)
/* F5BD4 802D1224 468010A0 */  cvt.s.w   $f2, $f2
/* F5BD8 802D1228 46020003 */  div.s     $f0, $f0, $f2
.L802D122C:
/* F5BDC 802D122C 8E240070 */  lw        $a0, 0x70($s1)
/* F5BE0 802D1230 8E450080 */  lw        $a1, 0x80($s2)
/* F5BE4 802D1234 44060000 */  mfc1      $a2, $f0
/* F5BE8 802D1238 0C0389DE */  jal       move_player
/* F5BEC 802D123C 00000000 */   nop      
.L802D1240:
/* F5BF0 802D1240 8E230070 */  lw        $v1, 0x70($s1)
/* F5BF4 802D1244 2463FFFF */  addiu     $v1, $v1, -1
/* F5BF8 802D1248 AE230070 */  sw        $v1, 0x70($s1)
/* F5BFC 802D124C 8FBF001C */  lw        $ra, 0x1c($sp)
/* F5C00 802D1250 8FB20018 */  lw        $s2, 0x18($sp)
/* F5C04 802D1254 8FB10014 */  lw        $s1, 0x14($sp)
/* F5C08 802D1258 8FB00010 */  lw        $s0, 0x10($sp)
/* F5C0C 802D125C D7B60028 */  ldc1      $f22, 0x28($sp)
/* F5C10 802D1260 D7B40020 */  ldc1      $f20, 0x20($sp)
/* F5C14 802D1264 000317C2 */  srl       $v0, $v1, 0x1f
/* F5C18 802D1268 03E00008 */  jr        $ra
/* F5C1C 802D126C 27BD0030 */   addiu    $sp, $sp, 0x30
