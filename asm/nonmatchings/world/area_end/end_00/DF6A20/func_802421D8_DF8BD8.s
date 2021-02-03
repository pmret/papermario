.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421D8_DF8BD8
/* DF8BD8 802421D8 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* DF8BDC 802421DC 3C05DC08 */  lui       $a1, 0xdc08
/* DF8BE0 802421E0 34A50008 */  ori       $a1, $a1, 8
/* DF8BE4 802421E4 AFB40030 */  sw        $s4, 0x30($sp)
/* DF8BE8 802421E8 0000A02D */  daddu     $s4, $zero, $zero
/* DF8BEC 802421EC AFB10024 */  sw        $s1, 0x24($sp)
/* DF8BF0 802421F0 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* DF8BF4 802421F4 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* DF8BF8 802421F8 AFB3002C */  sw        $s3, 0x2c($sp)
/* DF8BFC 802421FC 24130004 */  addiu     $s3, $zero, 4
/* DF8C00 80242200 3C028025 */  lui       $v0, %hi(D_80250EF0)
/* DF8C04 80242204 24420EF0 */  addiu     $v0, $v0, %lo(D_80250EF0)
/* DF8C08 80242208 AFBF0038 */  sw        $ra, 0x38($sp)
/* DF8C0C 8024220C AFB50034 */  sw        $s5, 0x34($sp)
/* DF8C10 80242210 AFB20028 */  sw        $s2, 0x28($sp)
/* DF8C14 80242214 AFB00020 */  sw        $s0, 0x20($sp)
/* DF8C18 80242218 8E230000 */  lw        $v1, ($s1)
/* DF8C1C 8024221C 3C108007 */  lui       $s0, %hi(gCurrentDisplayContextIndex)
/* DF8C20 80242220 8E1041F4 */  lw        $s0, %lo(gCurrentDisplayContextIndex)($s0)
/* DF8C24 80242224 3C158025 */  lui       $s5, %hi(D_8024F7E4)
/* DF8C28 80242228 8EB5F7E4 */  lw        $s5, %lo(D_8024F7E4)($s5)
/* DF8C2C 8024222C 44800000 */  mtc1      $zero, $f0
/* DF8C30 80242230 3C01C2C8 */  lui       $at, 0xc2c8
/* DF8C34 80242234 44811000 */  mtc1      $at, $f2
/* DF8C38 80242238 3C0142C8 */  lui       $at, 0x42c8
/* DF8C3C 8024223C 44812000 */  mtc1      $at, $f4
/* DF8C40 80242240 3C013F80 */  lui       $at, 0x3f80
/* DF8C44 80242244 44813000 */  mtc1      $at, $f6
/* DF8C48 80242248 3C0643A0 */  lui       $a2, 0x43a0
/* DF8C4C 8024224C 3C07C370 */  lui       $a3, 0xc370
/* DF8C50 80242250 0060402D */  daddu     $t0, $v1, $zero
/* DF8C54 80242254 24630008 */  addiu     $v1, $v1, 8
/* DF8C58 80242258 00108180 */  sll       $s0, $s0, 6
/* DF8C5C 8024225C 02028021 */  addu      $s0, $s0, $v0
/* DF8C60 80242260 0200202D */  daddu     $a0, $s0, $zero
/* DF8C64 80242264 02A0902D */  daddu     $s2, $s5, $zero
/* DF8C68 80242268 AE230000 */  sw        $v1, ($s1)
/* DF8C6C 8024226C AD050000 */  sw        $a1, ($t0)
/* DF8C70 80242270 44050000 */  mfc1      $a1, $f0
/* DF8C74 80242274 3C028024 */  lui       $v0, %hi(D_80242D60_DF9760)
/* DF8C78 80242278 24422D60 */  addiu     $v0, $v0, %lo(D_80242D60_DF9760)
/* DF8C7C 8024227C AD020004 */  sw        $v0, 4($t0)
/* DF8C80 80242280 E7A20014 */  swc1      $f2, 0x14($sp)
/* DF8C84 80242284 E7A40018 */  swc1      $f4, 0x18($sp)
/* DF8C88 80242288 E7A6001C */  swc1      $f6, 0x1c($sp)
/* DF8C8C 8024228C 0C018E90 */  jal       guOrtho
/* DF8C90 80242290 AFA50010 */   sw       $a1, 0x10($sp)
/* DF8C94 80242294 3C03DA38 */  lui       $v1, 0xda38
/* DF8C98 80242298 34630007 */  ori       $v1, $v1, 7
/* DF8C9C 8024229C 3C05D9C0 */  lui       $a1, 0xd9c0
/* DF8CA0 802422A0 34A5F9FB */  ori       $a1, $a1, 0xf9fb
/* DF8CA4 802422A4 3C07D9FF */  lui       $a3, 0xd9ff
/* DF8CA8 802422A8 34E7FFFF */  ori       $a3, $a3, 0xffff
/* DF8CAC 802422AC 3C060020 */  lui       $a2, 0x20
/* DF8CB0 802422B0 8E220000 */  lw        $v0, ($s1)
/* DF8CB4 802422B4 00D33025 */  or        $a2, $a2, $s3
/* DF8CB8 802422B8 0040202D */  daddu     $a0, $v0, $zero
/* DF8CBC 802422BC 24420008 */  addiu     $v0, $v0, 8
/* DF8CC0 802422C0 AE220000 */  sw        $v0, ($s1)
/* DF8CC4 802422C4 AC830000 */  sw        $v1, ($a0)
/* DF8CC8 802422C8 3C038000 */  lui       $v1, 0x8000
/* DF8CCC 802422CC 02038021 */  addu      $s0, $s0, $v1
/* DF8CD0 802422D0 24430008 */  addiu     $v1, $v0, 8
/* DF8CD4 802422D4 AC900004 */  sw        $s0, 4($a0)
/* DF8CD8 802422D8 AE230000 */  sw        $v1, ($s1)
/* DF8CDC 802422DC 3C03E700 */  lui       $v1, 0xe700
/* DF8CE0 802422E0 AC430000 */  sw        $v1, ($v0)
/* DF8CE4 802422E4 24430010 */  addiu     $v1, $v0, 0x10
/* DF8CE8 802422E8 AC400004 */  sw        $zero, 4($v0)
/* DF8CEC 802422EC AE230000 */  sw        $v1, ($s1)
/* DF8CF0 802422F0 24430018 */  addiu     $v1, $v0, 0x18
/* DF8CF4 802422F4 AC450008 */  sw        $a1, 8($v0)
/* DF8CF8 802422F8 AC40000C */  sw        $zero, 0xc($v0)
/* DF8CFC 802422FC AE230000 */  sw        $v1, ($s1)
/* DF8D00 80242300 AC470010 */  sw        $a3, 0x10($v0)
/* DF8D04 80242304 AC460014 */  sw        $a2, 0x14($v0)
.L80242308:
/* DF8D08 80242308 96420074 */  lhu       $v0, 0x74($s2)
/* DF8D0C 8024230C 30420001 */  andi      $v0, $v0, 1
/* DF8D10 80242310 50400004 */  beql      $v0, $zero, .L80242324
/* DF8D14 80242314 26730074 */   addiu    $s3, $s3, 0x74
/* DF8D18 80242318 0C0906CD */  jal       func_80241B34_DF8534
/* DF8D1C 8024231C 02B32021 */   addu     $a0, $s5, $s3
/* DF8D20 80242320 26730074 */  addiu     $s3, $s3, 0x74
.L80242324:
/* DF8D24 80242324 26940001 */  addiu     $s4, $s4, 1
/* DF8D28 80242328 2A820020 */  slti      $v0, $s4, 0x20
/* DF8D2C 8024232C 1440FFF6 */  bnez      $v0, .L80242308
/* DF8D30 80242330 26520074 */   addiu    $s2, $s2, 0x74
/* DF8D34 80242334 8FBF0038 */  lw        $ra, 0x38($sp)
/* DF8D38 80242338 8FB50034 */  lw        $s5, 0x34($sp)
/* DF8D3C 8024233C 8FB40030 */  lw        $s4, 0x30($sp)
/* DF8D40 80242340 8FB3002C */  lw        $s3, 0x2c($sp)
/* DF8D44 80242344 8FB20028 */  lw        $s2, 0x28($sp)
/* DF8D48 80242348 8FB10024 */  lw        $s1, 0x24($sp)
/* DF8D4C 8024234C 8FB00020 */  lw        $s0, 0x20($sp)
/* DF8D50 80242350 03E00008 */  jr        $ra
/* DF8D54 80242354 27BD0040 */   addiu    $sp, $sp, 0x40
