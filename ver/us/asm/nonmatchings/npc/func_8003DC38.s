.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003DC38
/* 19038 8003DC38 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 1903C 8003DC3C 3C028007 */  lui       $v0, %hi(D_80077C2C)
/* 19040 8003DC40 24427C2C */  addiu     $v0, $v0, %lo(D_80077C2C)
/* 19044 8003DC44 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19048 8003DC48 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1904C 8003DC4C AFB20018 */  sw        $s2, 0x18($sp)
/* 19050 8003DC50 AFB10014 */  sw        $s1, 0x14($sp)
/* 19054 8003DC54 AFB00010 */  sw        $s0, 0x10($sp)
/* 19058 8003DC58 F7BE0050 */  sdc1      $f30, 0x50($sp)
/* 1905C 8003DC5C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 19060 8003DC60 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 19064 8003DC64 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 19068 8003DC68 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 1906C 8003DC6C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 19070 8003DC70 C4400000 */  lwc1      $f0, ($v0)
/* 19074 8003DC74 3C013DCC */  lui       $at, 0x3dcc
/* 19078 8003DC78 3421CCCD */  ori       $at, $at, 0xcccd
/* 1907C 8003DC7C 44811000 */  mtc1      $at, $f2
/* 19080 8003DC80 00000000 */  nop
/* 19084 8003DC84 46020000 */  add.s     $f0, $f0, $f2
/* 19088 8003DC88 E4400000 */  swc1      $f0, ($v0)
/* 1908C 8003DC8C 24020002 */  addiu     $v0, $zero, 2
/* 19090 8003DC90 14A2006B */  bne       $a1, $v0, .L8003DE40
/* 19094 8003DC94 0080882D */   daddu    $s1, $a0, $zero
/* 19098 8003DC98 3C108007 */  lui       $s0, %hi(D_80077C24)
/* 1909C 8003DC9C 26107C24 */  addiu     $s0, $s0, %lo(D_80077C24)
/* 190A0 8003DCA0 C62E003C */  lwc1      $f14, 0x3c($s1)
/* 190A4 8003DCA4 3C014160 */  lui       $at, 0x4160
/* 190A8 8003DCA8 44810000 */  mtc1      $at, $f0
/* 190AC 8003DCAC C62C0038 */  lwc1      $f12, 0x38($s1)
/* 190B0 8003DCB0 46007380 */  add.s     $f14, $f14, $f0
/* 190B4 8003DCB4 3C0140A0 */  lui       $at, 0x40a0
/* 190B8 8003DCB8 44810000 */  mtc1      $at, $f0
/* 190BC 8003DCBC 8E260040 */  lw        $a2, 0x40($s1)
/* 190C0 8003DCC0 8E070000 */  lw        $a3, ($s0)
/* 190C4 8003DCC4 0C01BF14 */  jal       fx_cloud_puff
/* 190C8 8003DCC8 46007381 */   sub.s    $f14, $f14, $f0
/* 190CC 8003DCCC C6000000 */  lwc1      $f0, ($s0)
/* 190D0 8003DCD0 3C01420C */  lui       $at, 0x420c
/* 190D4 8003DCD4 44816000 */  mtc1      $at, $f12
/* 190D8 8003DCD8 0000982D */  daddu     $s3, $zero, $zero
/* 190DC 8003DCDC 460C0300 */  add.s     $f12, $f0, $f12
/* 190E0 8003DCE0 3C01BE99 */  lui       $at, 0xbe99
/* 190E4 8003DCE4 3421999A */  ori       $at, $at, 0x999a
/* 190E8 8003DCE8 4481F000 */  mtc1      $at, $f30
/* 190EC 8003DCEC 0C00A6C9 */  jal       clamp_angle
/* 190F0 8003DCF0 0260902D */   daddu    $s2, $s3, $zero
/* 190F4 8003DCF4 E6000000 */  swc1      $f0, ($s0)
.L8003DCF8:
/* 190F8 8003DCF8 0C00A67F */  jal       rand_int
/* 190FC 8003DCFC 2404000A */   addiu    $a0, $zero, 0xa
/* 19100 8003DD00 2442FFFB */  addiu     $v0, $v0, -5
/* 19104 8003DD04 4482B000 */  mtc1      $v0, $f22
/* 19108 8003DD08 00000000 */  nop
/* 1910C 8003DD0C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 19110 8003DD10 0C00A67F */  jal       rand_int
/* 19114 8003DD14 2404000A */   addiu    $a0, $zero, 0xa
/* 19118 8003DD18 4616B082 */  mul.s     $f2, $f22, $f22
/* 1911C 8003DD1C 00000000 */  nop
/* 19120 8003DD20 2442FFFB */  addiu     $v0, $v0, -5
/* 19124 8003DD24 4482C000 */  mtc1      $v0, $f24
/* 19128 8003DD28 00000000 */  nop
/* 1912C 8003DD2C 4680C620 */  cvt.s.w   $f24, $f24
/* 19130 8003DD30 4618C102 */  mul.s     $f4, $f24, $f24
/* 19134 8003DD34 00000000 */  nop
/* 19138 8003DD38 C62C000C */  lwc1      $f12, 0xc($s1)
/* 1913C 8003DD3C 44920000 */  mtc1      $s2, $f0
/* 19140 8003DD40 00000000 */  nop
/* 19144 8003DD44 46800020 */  cvt.s.w   $f0, $f0
/* 19148 8003DD48 46006307 */  neg.s     $f12, $f12
/* 1914C 8003DD4C 46006300 */  add.s     $f12, $f12, $f0
/* 19150 8003DD50 3C01C000 */  lui       $at, 0xc000
/* 19154 8003DD54 4481A000 */  mtc1      $at, $f20
/* 19158 8003DD58 3C0140A0 */  lui       $at, 0x40a0
/* 1915C 8003DD5C 44810000 */  mtc1      $at, $f0
/* 19160 8003DD60 46041080 */  add.s     $f2, $f2, $f4
/* 19164 8003DD64 3C018007 */  lui       $at, %hi(D_80077C28)
/* 19168 8003DD68 A4207C28 */  sh        $zero, %lo(D_80077C28)($at)
/* 1916C 8003DD6C 46001083 */  div.s     $f2, $f2, $f0
/* 19170 8003DD70 0C00A6C9 */  jal       clamp_angle
/* 19174 8003DD74 4602A501 */   sub.s    $f20, $f20, $f2
/* 19178 8003DD78 3C0140C9 */  lui       $at, 0x40c9
/* 1917C 8003DD7C 34210FD0 */  ori       $at, $at, 0xfd0
/* 19180 8003DD80 44811000 */  mtc1      $at, $f2
/* 19184 8003DD84 00000000 */  nop
/* 19188 8003DD88 46020002 */  mul.s     $f0, $f0, $f2
/* 1918C 8003DD8C 00000000 */  nop
/* 19190 8003DD90 3C0143B4 */  lui       $at, 0x43b4
/* 19194 8003DD94 44811000 */  mtc1      $at, $f2
/* 19198 8003DD98 00000000 */  nop
/* 1919C 8003DD9C 46020683 */  div.s     $f26, $f0, $f2
/* 191A0 8003DDA0 0C00A85B */  jal       sin_rad
/* 191A4 8003DDA4 4600D306 */   mov.s    $f12, $f26
/* 191A8 8003DDA8 46000706 */  mov.s     $f28, $f0
/* 191AC 8003DDAC 0C00A874 */  jal       cos_rad
/* 191B0 8003DDB0 4600D306 */   mov.s    $f12, $f26
/* 191B4 8003DDB4 862200A6 */  lh        $v0, 0xa6($s1)
/* 191B8 8003DDB8 44822000 */  mtc1      $v0, $f4
/* 191BC 8003DDBC 00000000 */  nop
/* 191C0 8003DDC0 46802120 */  cvt.s.w   $f4, $f4
/* 191C4 8003DDC4 461C2182 */  mul.s     $f6, $f4, $f28
/* 191C8 8003DDC8 00000000 */  nop
/* 191CC 8003DDCC 46002102 */  mul.s     $f4, $f4, $f0
/* 191D0 8003DDD0 00000000 */  nop
/* 191D4 8003DDD4 3C014178 */  lui       $at, 0x4178
/* 191D8 8003DDD8 44811000 */  mtc1      $at, $f2
/* 191DC 8003DDDC C620003C */  lwc1      $f0, 0x3c($s1)
/* 191E0 8003DDE0 46020000 */  add.s     $f0, $f0, $f2
/* 191E4 8003DDE4 46140000 */  add.s     $f0, $f0, $f20
/* 191E8 8003DDE8 461E3182 */  mul.s     $f6, $f6, $f30
/* 191EC 8003DDEC 00000000 */  nop
/* 191F0 8003DDF0 44060000 */  mfc1      $a2, $f0
/* 191F4 8003DDF4 C6200038 */  lwc1      $f0, 0x38($s1)
/* 191F8 8003DDF8 46060000 */  add.s     $f0, $f0, $f6
/* 191FC 8003DDFC 46160000 */  add.s     $f0, $f0, $f22
/* 19200 8003DE00 461E2102 */  mul.s     $f4, $f4, $f30
/* 19204 8003DE04 00000000 */  nop
/* 19208 8003DE08 44050000 */  mfc1      $a1, $f0
/* 1920C 8003DE0C C6200040 */  lwc1      $f0, 0x40($s1)
/* 19210 8003DE10 46040000 */  add.s     $f0, $f0, $f4
/* 19214 8003DE14 46180000 */  add.s     $f0, $f0, $f24
/* 19218 8003DE18 2652005A */  addiu     $s2, $s2, 0x5a
/* 1921C 8003DE1C 26730001 */  addiu     $s3, $s3, 1
/* 19220 8003DE20 44070000 */  mfc1      $a3, $f0
/* 19224 8003DE24 0C01BF2C */  jal       fx_cloud_trail
/* 19228 8003DE28 24040001 */   addiu    $a0, $zero, 1
/* 1922C 8003DE2C 2A620004 */  slti      $v0, $s3, 4
/* 19230 8003DE30 1040004E */  beqz      $v0, .L8003DF6C
/* 19234 8003DE34 00000000 */   nop
/* 19238 8003DE38 0800F73E */  j         .L8003DCF8
/* 1923C 8003DE3C 00000000 */   nop
.L8003DE40:
/* 19240 8003DE40 0C00A67F */  jal       rand_int
/* 19244 8003DE44 2404000A */   addiu    $a0, $zero, 0xa
/* 19248 8003DE48 2442FFFB */  addiu     $v0, $v0, -5
/* 1924C 8003DE4C 4482C000 */  mtc1      $v0, $f24
/* 19250 8003DE50 00000000 */  nop
/* 19254 8003DE54 4680C620 */  cvt.s.w   $f24, $f24
/* 19258 8003DE58 0C00A67F */  jal       rand_int
/* 1925C 8003DE5C 2404000A */   addiu    $a0, $zero, 0xa
/* 19260 8003DE60 4618C002 */  mul.s     $f0, $f24, $f24
/* 19264 8003DE64 00000000 */  nop
/* 19268 8003DE68 2442FFFB */  addiu     $v0, $v0, -5
/* 1926C 8003DE6C 4482B000 */  mtc1      $v0, $f22
/* 19270 8003DE70 00000000 */  nop
/* 19274 8003DE74 4680B5A0 */  cvt.s.w   $f22, $f22
/* 19278 8003DE78 4616B082 */  mul.s     $f2, $f22, $f22
/* 1927C 8003DE7C 00000000 */  nop
/* 19280 8003DE80 C62C000C */  lwc1      $f12, 0xc($s1)
/* 19284 8003DE84 3C01C000 */  lui       $at, 0xc000
/* 19288 8003DE88 4481A000 */  mtc1      $at, $f20
/* 1928C 8003DE8C 46020000 */  add.s     $f0, $f0, $f2
/* 19290 8003DE90 3C018007 */  lui       $at, %hi(D_80077C28)
/* 19294 8003DE94 A4207C28 */  sh        $zero, %lo(D_80077C28)($at)
/* 19298 8003DE98 3C0140A0 */  lui       $at, 0x40a0
/* 1929C 8003DE9C 44811000 */  mtc1      $at, $f2
/* 192A0 8003DEA0 46006307 */  neg.s     $f12, $f12
/* 192A4 8003DEA4 46020003 */  div.s     $f0, $f0, $f2
/* 192A8 8003DEA8 0C00A6C9 */  jal       clamp_angle
/* 192AC 8003DEAC 4600A501 */   sub.s    $f20, $f20, $f0
/* 192B0 8003DEB0 3C0140C9 */  lui       $at, 0x40c9
/* 192B4 8003DEB4 34210FD0 */  ori       $at, $at, 0xfd0
/* 192B8 8003DEB8 44811000 */  mtc1      $at, $f2
/* 192BC 8003DEBC 00000000 */  nop
/* 192C0 8003DEC0 46020002 */  mul.s     $f0, $f0, $f2
/* 192C4 8003DEC4 00000000 */  nop
/* 192C8 8003DEC8 3C0143B4 */  lui       $at, 0x43b4
/* 192CC 8003DECC 44811000 */  mtc1      $at, $f2
/* 192D0 8003DED0 00000000 */  nop
/* 192D4 8003DED4 46020683 */  div.s     $f26, $f0, $f2
/* 192D8 8003DED8 0C00A85B */  jal       sin_rad
/* 192DC 8003DEDC 4600D306 */   mov.s    $f12, $f26
/* 192E0 8003DEE0 46000706 */  mov.s     $f28, $f0
/* 192E4 8003DEE4 0C00A874 */  jal       cos_rad
/* 192E8 8003DEE8 4600D306 */   mov.s    $f12, $f26
/* 192EC 8003DEEC 862200A6 */  lh        $v0, 0xa6($s1)
/* 192F0 8003DEF0 44822000 */  mtc1      $v0, $f4
/* 192F4 8003DEF4 00000000 */  nop
/* 192F8 8003DEF8 46802120 */  cvt.s.w   $f4, $f4
/* 192FC 8003DEFC 461C2182 */  mul.s     $f6, $f4, $f28
/* 19300 8003DF00 00000000 */  nop
/* 19304 8003DF04 46002102 */  mul.s     $f4, $f4, $f0
/* 19308 8003DF08 00000000 */  nop
/* 1930C 8003DF0C 3C01BE99 */  lui       $at, 0xbe99
/* 19310 8003DF10 3421999A */  ori       $at, $at, 0x999a
/* 19314 8003DF14 44810000 */  mtc1      $at, $f0
/* 19318 8003DF18 00000000 */  nop
/* 1931C 8003DF1C 46003182 */  mul.s     $f6, $f6, $f0
/* 19320 8003DF20 00000000 */  nop
/* 19324 8003DF24 46002102 */  mul.s     $f4, $f4, $f0
/* 19328 8003DF28 00000000 */  nop
/* 1932C 8003DF2C 3C014178 */  lui       $at, 0x4178
/* 19330 8003DF30 44811000 */  mtc1      $at, $f2
/* 19334 8003DF34 C620003C */  lwc1      $f0, 0x3c($s1)
/* 19338 8003DF38 46020000 */  add.s     $f0, $f0, $f2
/* 1933C 8003DF3C 46140000 */  add.s     $f0, $f0, $f20
/* 19340 8003DF40 44060000 */  mfc1      $a2, $f0
/* 19344 8003DF44 C6200038 */  lwc1      $f0, 0x38($s1)
/* 19348 8003DF48 46060000 */  add.s     $f0, $f0, $f6
/* 1934C 8003DF4C 46180000 */  add.s     $f0, $f0, $f24
/* 19350 8003DF50 44050000 */  mfc1      $a1, $f0
/* 19354 8003DF54 C6200040 */  lwc1      $f0, 0x40($s1)
/* 19358 8003DF58 46040000 */  add.s     $f0, $f0, $f4
/* 1935C 8003DF5C 46160000 */  add.s     $f0, $f0, $f22
/* 19360 8003DF60 44070000 */  mfc1      $a3, $f0
/* 19364 8003DF64 0C01BF2C */  jal       fx_cloud_trail
/* 19368 8003DF68 24040001 */   addiu    $a0, $zero, 1
.L8003DF6C:
/* 1936C 8003DF6C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19370 8003DF70 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19374 8003DF74 8FB20018 */  lw        $s2, 0x18($sp)
/* 19378 8003DF78 8FB10014 */  lw        $s1, 0x14($sp)
/* 1937C 8003DF7C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19380 8003DF80 D7BE0050 */  ldc1      $f30, 0x50($sp)
/* 19384 8003DF84 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 19388 8003DF88 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 1938C 8003DF8C D7B80038 */  ldc1      $f24, 0x38($sp)
/* 19390 8003DF90 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 19394 8003DF94 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 19398 8003DF98 03E00008 */  jr        $ra
/* 1939C 8003DF9C 27BD0058 */   addiu    $sp, $sp, 0x58
