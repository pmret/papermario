.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel battle_item_mystery_func_802A123C_72C7EC
/* 72C7EC 802A123C 3C03802A */  lui       $v1, %hi(D_802A25E4)
/* 72C7F0 802A1240 8C6325E4 */  lw        $v1, %lo(D_802A25E4)($v1)
/* 72C7F4 802A1244 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 72C7F8 802A1248 AFBF0064 */  sw        $ra, 0x64($sp)
/* 72C7FC 802A124C AFB40060 */  sw        $s4, 0x60($sp)
/* 72C800 802A1250 AFB3005C */  sw        $s3, 0x5c($sp)
/* 72C804 802A1254 AFB20058 */  sw        $s2, 0x58($sp)
/* 72C808 802A1258 AFB10054 */  sw        $s1, 0x54($sp)
/* 72C80C 802A125C 28620006 */  slti      $v0, $v1, 6
/* 72C810 802A1260 10400058 */  beqz      $v0, .L802A13C4
/* 72C814 802A1264 AFB00050 */   sw       $s0, 0x50($sp)
/* 72C818 802A1268 18600056 */  blez      $v1, .L802A13C4
/* 72C81C 802A126C 24050007 */   addiu    $a1, $zero, 7
/* 72C820 802A1270 0000202D */  daddu     $a0, $zero, $zero
/* 72C824 802A1274 2406006A */  addiu     $a2, $zero, 0x6a
/* 72C828 802A1278 24020024 */  addiu     $v0, $zero, 0x24
/* 72C82C 802A127C AFA20014 */  sw        $v0, 0x14($sp)
/* 72C830 802A1280 AFA20018 */  sw        $v0, 0x18($sp)
/* 72C834 802A1284 240200FF */  addiu     $v0, $zero, 0xff
/* 72C838 802A1288 AFA2001C */  sw        $v0, 0x1c($sp)
/* 72C83C 802A128C 24020140 */  addiu     $v0, $zero, 0x140
/* 72C840 802A1290 AFA20044 */  sw        $v0, 0x44($sp)
/* 72C844 802A1294 240200F0 */  addiu     $v0, $zero, 0xf0
/* 72C848 802A1298 24070056 */  addiu     $a3, $zero, 0x56
/* 72C84C 802A129C AFA00010 */  sw        $zero, 0x10($sp)
/* 72C850 802A12A0 AFA00020 */  sw        $zero, 0x20($sp)
/* 72C854 802A12A4 AFA00024 */  sw        $zero, 0x24($sp)
/* 72C858 802A12A8 AFA00028 */  sw        $zero, 0x28($sp)
/* 72C85C 802A12AC AFA0002C */  sw        $zero, 0x2c($sp)
/* 72C860 802A12B0 AFA00030 */  sw        $zero, 0x30($sp)
/* 72C864 802A12B4 AFA00034 */  sw        $zero, 0x34($sp)
/* 72C868 802A12B8 AFA00038 */  sw        $zero, 0x38($sp)
/* 72C86C 802A12BC AFA0003C */  sw        $zero, 0x3c($sp)
/* 72C870 802A12C0 AFA00040 */  sw        $zero, 0x40($sp)
/* 72C874 802A12C4 AFA20048 */  sw        $v0, 0x48($sp)
/* 72C878 802A12C8 0C03D4B8 */  jal       draw_box
/* 72C87C 802A12CC AFA0004C */   sw       $zero, 0x4c($sp)
/* 72C880 802A12D0 3C06ED1B */  lui       $a2, 0xed1b
/* 72C884 802A12D4 34C60168 */  ori       $a2, $a2, 0x168
/* 72C888 802A12D8 3C050022 */  lui       $a1, 0x22
/* 72C88C 802A12DC 34A5C1D8 */  ori       $a1, $a1, 0xc1d8
/* 72C890 802A12E0 0000882D */  daddu     $s1, $zero, $zero
/* 72C894 802A12E4 3C1451EB */  lui       $s4, 0x51eb
/* 72C898 802A12E8 3694851F */  ori       $s4, $s4, 0x851f
/* 72C89C 802A12EC 0220982D */  daddu     $s3, $s1, $zero
/* 72C8A0 802A12F0 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 72C8A4 802A12F4 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 72C8A8 802A12F8 8C820000 */  lw        $v0, ($a0)
/* 72C8AC 802A12FC 3C12802A */  lui       $s2, %hi(D_802A25C8)
/* 72C8B0 802A1300 265225C8 */  addiu     $s2, $s2, %lo(D_802A25C8)
/* 72C8B4 802A1304 0040182D */  daddu     $v1, $v0, $zero
/* 72C8B8 802A1308 24420008 */  addiu     $v0, $v0, 8
/* 72C8BC 802A130C AC820000 */  sw        $v0, ($a0)
/* 72C8C0 802A1310 AC660000 */  sw        $a2, ($v1)
/* 72C8C4 802A1314 AC650004 */  sw        $a1, 4($v1)
.L802A1318:
/* 72C8C8 802A1318 2405007C */  addiu     $a1, $zero, 0x7c
/* 72C8CC 802A131C 3C02802A */  lui       $v0, %hi(D_802A25EC)
/* 72C8D0 802A1320 8C4225EC */  lw        $v0, %lo(D_802A25EC)($v0)
/* 72C8D4 802A1324 8E500000 */  lw        $s0, ($s2)
/* 72C8D8 802A1328 00540018 */  mult      $v0, $s4
/* 72C8DC 802A132C 26520004 */  addiu     $s2, $s2, 4
/* 72C8E0 802A1330 26310001 */  addiu     $s1, $s1, 1
/* 72C8E4 802A1334 0200202D */  daddu     $a0, $s0, $zero
/* 72C8E8 802A1338 000217C3 */  sra       $v0, $v0, 0x1f
/* 72C8EC 802A133C 00004010 */  mfhi      $t0
/* 72C8F0 802A1340 00083143 */  sra       $a2, $t0, 5
/* 72C8F4 802A1344 00C23023 */  subu      $a2, $a2, $v0
/* 72C8F8 802A1348 24C6FF98 */  addiu     $a2, $a2, -0x68
/* 72C8FC 802A134C 0C051261 */  jal       set_hud_element_render_pos
/* 72C900 802A1350 02663023 */   subu     $a2, $s3, $a2
/* 72C904 802A1354 0C0511F8 */  jal       draw_hud_element_3
/* 72C908 802A1358 0200202D */   daddu    $a0, $s0, $zero
/* 72C90C 802A135C 2A220007 */  slti      $v0, $s1, 7
/* 72C910 802A1360 1440FFED */  bnez      $v0, .L802A1318
/* 72C914 802A1364 2673001A */   addiu    $s3, $s3, 0x1a
/* 72C918 802A1368 3C0251EB */  lui       $v0, 0x51eb
/* 72C91C 802A136C 3442851F */  ori       $v0, $v0, 0x851f
/* 72C920 802A1370 2405007C */  addiu     $a1, $zero, 0x7c
/* 72C924 802A1374 00113040 */  sll       $a2, $s1, 1
/* 72C928 802A1378 00D13021 */  addu      $a2, $a2, $s1
/* 72C92C 802A137C 00063080 */  sll       $a2, $a2, 2
/* 72C930 802A1380 3C03802A */  lui       $v1, %hi(D_802A25EC)
/* 72C934 802A1384 8C6325EC */  lw        $v1, %lo(D_802A25EC)($v1)
/* 72C938 802A1388 00D13021 */  addu      $a2, $a2, $s1
/* 72C93C 802A138C 00620018 */  mult      $v1, $v0
/* 72C940 802A1390 3C10802A */  lui       $s0, %hi(D_802A25C8)
/* 72C944 802A1394 8E1025C8 */  lw        $s0, %lo(D_802A25C8)($s0)
/* 72C948 802A1398 00063040 */  sll       $a2, $a2, 1
/* 72C94C 802A139C 0200202D */  daddu     $a0, $s0, $zero
/* 72C950 802A13A0 00031FC3 */  sra       $v1, $v1, 0x1f
/* 72C954 802A13A4 00004010 */  mfhi      $t0
/* 72C958 802A13A8 00081143 */  sra       $v0, $t0, 5
/* 72C95C 802A13AC 00431023 */  subu      $v0, $v0, $v1
/* 72C960 802A13B0 2442FF98 */  addiu     $v0, $v0, -0x68
/* 72C964 802A13B4 0C051261 */  jal       set_hud_element_render_pos
/* 72C968 802A13B8 00C23023 */   subu     $a2, $a2, $v0
/* 72C96C 802A13BC 0C0511F8 */  jal       draw_hud_element_3
/* 72C970 802A13C0 0200202D */   daddu    $a0, $s0, $zero
.L802A13C4:
/* 72C974 802A13C4 8FBF0064 */  lw        $ra, 0x64($sp)
/* 72C978 802A13C8 8FB40060 */  lw        $s4, 0x60($sp)
/* 72C97C 802A13CC 8FB3005C */  lw        $s3, 0x5c($sp)
/* 72C980 802A13D0 8FB20058 */  lw        $s2, 0x58($sp)
/* 72C984 802A13D4 8FB10054 */  lw        $s1, 0x54($sp)
/* 72C988 802A13D8 8FB00050 */  lw        $s0, 0x50($sp)
/* 72C98C 802A13DC 03E00008 */  jr        $ra
/* 72C990 802A13E0 27BD0068 */   addiu    $sp, $sp, 0x68
