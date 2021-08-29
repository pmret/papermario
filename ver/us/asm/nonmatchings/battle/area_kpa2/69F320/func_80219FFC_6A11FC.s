.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219FFC_6A11FC
/* 6A11FC 80219FFC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 6A1200 8021A000 AFB3002C */  sw        $s3, 0x2c($sp)
/* 6A1204 8021A004 0080982D */  daddu     $s3, $a0, $zero
/* 6A1208 8021A008 AFB00020 */  sw        $s0, 0x20($sp)
/* 6A120C 8021A00C 0000802D */  daddu     $s0, $zero, $zero
/* 6A1210 8021A010 AFB20028 */  sw        $s2, 0x28($sp)
/* 6A1214 8021A014 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 6A1218 8021A018 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 6A121C 8021A01C AFB40030 */  sw        $s4, 0x30($sp)
/* 6A1220 8021A020 3C148011 */  lui       $s4, %hi(gPlayerData)
/* 6A1224 8021A024 2694F290 */  addiu     $s4, $s4, %lo(gPlayerData)
/* 6A1228 8021A028 AFB50034 */  sw        $s5, 0x34($sp)
/* 6A122C 8021A02C 2404FFFF */  addiu     $a0, $zero, -1
/* 6A1230 8021A030 AFBF0038 */  sw        $ra, 0x38($sp)
/* 6A1234 8021A034 AFB10024 */  sw        $s1, 0x24($sp)
/* 6A1238 8021A038 824200AE */  lb        $v0, 0xae($s2)
/* 6A123C 8021A03C 8E71000C */  lw        $s1, 0xc($s3)
/* 6A1240 8021A040 14440003 */  bne       $v0, $a0, .L8021A050
/* 6A1244 8021A044 0280A82D */   daddu    $s5, $s4, $zero
/* 6A1248 8021A048 AFA00010 */  sw        $zero, 0x10($sp)
/* 6A124C 8021A04C 24100001 */  addiu     $s0, $zero, 1
.L8021A050:
/* 6A1250 8021A050 824200AF */  lb        $v0, 0xaf($s2)
/* 6A1254 8021A054 14440005 */  bne       $v0, $a0, .L8021A06C
/* 6A1258 8021A058 00101080 */   sll      $v0, $s0, 2
/* 6A125C 8021A05C 03A21821 */  addu      $v1, $sp, $v0
/* 6A1260 8021A060 24020001 */  addiu     $v0, $zero, 1
/* 6A1264 8021A064 AC620010 */  sw        $v0, 0x10($v1)
/* 6A1268 8021A068 02028021 */  addu      $s0, $s0, $v0
.L8021A06C:
/* 6A126C 8021A06C 824200B0 */  lb        $v0, 0xb0($s2)
/* 6A1270 8021A070 14440005 */  bne       $v0, $a0, .L8021A088
/* 6A1274 8021A074 00101080 */   sll      $v0, $s0, 2
/* 6A1278 8021A078 03A21821 */  addu      $v1, $sp, $v0
/* 6A127C 8021A07C 24020002 */  addiu     $v0, $zero, 2
/* 6A1280 8021A080 AC620010 */  sw        $v0, 0x10($v1)
/* 6A1284 8021A084 26100001 */  addiu     $s0, $s0, 1
.L8021A088:
/* 6A1288 8021A088 0C00A67F */  jal       rand_int
/* 6A128C 8021A08C 24040002 */   addiu    $a0, $zero, 2
/* 6A1290 8021A090 2604FFFF */  addiu     $a0, $s0, -1
/* 6A1294 8021A094 0C00A67F */  jal       rand_int
/* 6A1298 8021A098 24500002 */   addiu    $s0, $v0, 2
/* 6A129C 8021A09C 00021080 */  sll       $v0, $v0, 2
/* 6A12A0 8021A0A0 03A21021 */  addu      $v0, $sp, $v0
/* 6A12A4 8021A0A4 8C430010 */  lw        $v1, 0x10($v0)
/* 6A12A8 8021A0A8 24020001 */  addiu     $v0, $zero, 1
/* 6A12AC 8021A0AC 1062001C */  beq       $v1, $v0, .L8021A120
/* 6A12B0 8021A0B0 28620002 */   slti     $v0, $v1, 2
/* 6A12B4 8021A0B4 10400005 */  beqz      $v0, .L8021A0CC
/* 6A12B8 8021A0B8 24020002 */   addiu    $v0, $zero, 2
/* 6A12BC 8021A0BC 50600007 */  beql      $v1, $zero, .L8021A0DC
/* 6A12C0 8021A0C0 A25000AE */   sb       $s0, 0xae($s2)
/* 6A12C4 8021A0C4 08086864 */  j         .L8021A190
/* 6A12C8 8021A0C8 00000000 */   nop
.L8021A0CC:
/* 6A12CC 8021A0CC 50620026 */  beql      $v1, $v0, .L8021A168
/* 6A12D0 8021A0D0 A25000B0 */   sb       $s0, 0xb0($s2)
/* 6A12D4 8021A0D4 08086864 */  j         .L8021A190
/* 6A12D8 8021A0D8 00000000 */   nop
.L8021A0DC:
/* 6A12DC 8021A0DC 8E250000 */  lw        $a1, ($s1)
/* 6A12E0 8021A0E0 82820001 */  lb        $v0, 1($s4)
/* 6A12E4 8021A0E4 26310004 */  addiu     $s1, $s1, 4
/* 6A12E8 8021A0E8 00021080 */  sll       $v0, $v0, 2
/* 6A12EC 8021A0EC 3C068022 */  lui       $a2, %hi(D_8022466C_6AB86C)
/* 6A12F0 8021A0F0 00C23021 */  addu      $a2, $a2, $v0
/* 6A12F4 8021A0F4 8CC6466C */  lw        $a2, %lo(D_8022466C_6AB86C)($a2)
/* 6A12F8 8021A0F8 0C0B2026 */  jal       evt_set_variable
/* 6A12FC 8021A0FC 0260202D */   daddu    $a0, $s3, $zero
/* 6A1300 8021A100 82820001 */  lb        $v0, 1($s4)
/* 6A1304 8021A104 8E250000 */  lw        $a1, ($s1)
/* 6A1308 8021A108 00021080 */  sll       $v0, $v0, 2
/* 6A130C 8021A10C 3C068022 */  lui       $a2, %hi(D_80224678_6AB878)
/* 6A1310 8021A110 00C23021 */  addu      $a2, $a2, $v0
/* 6A1314 8021A114 8CC64678 */  lw        $a2, %lo(D_80224678_6AB878)($a2)
/* 6A1318 8021A118 08086862 */  j         .L8021A188
/* 6A131C 8021A11C 0260202D */   daddu    $a0, $s3, $zero
.L8021A120:
/* 6A1320 8021A120 A25000AF */  sb        $s0, 0xaf($s2)
/* 6A1324 8021A124 8E250000 */  lw        $a1, ($s1)
/* 6A1328 8021A128 82A20000 */  lb        $v0, ($s5)
/* 6A132C 8021A12C 26310004 */  addiu     $s1, $s1, 4
/* 6A1330 8021A130 00021080 */  sll       $v0, $v0, 2
/* 6A1334 8021A134 3C068022 */  lui       $a2, %hi(D_80224684_6AB884)
/* 6A1338 8021A138 00C23021 */  addu      $a2, $a2, $v0
/* 6A133C 8021A13C 8CC64684 */  lw        $a2, %lo(D_80224684_6AB884)($a2)
/* 6A1340 8021A140 0C0B2026 */  jal       evt_set_variable
/* 6A1344 8021A144 0260202D */   daddu    $a0, $s3, $zero
/* 6A1348 8021A148 82A20000 */  lb        $v0, ($s5)
/* 6A134C 8021A14C 8E250000 */  lw        $a1, ($s1)
/* 6A1350 8021A150 00021080 */  sll       $v0, $v0, 2
/* 6A1354 8021A154 3C068022 */  lui       $a2, %hi(D_80224690_6AB890)
/* 6A1358 8021A158 00C23021 */  addu      $a2, $a2, $v0
/* 6A135C 8021A15C 8CC64690 */  lw        $a2, %lo(D_80224690_6AB890)($a2)
/* 6A1360 8021A160 08086862 */  j         .L8021A188
/* 6A1364 8021A164 0260202D */   daddu    $a0, $s3, $zero
.L8021A168:
/* 6A1368 8021A168 8E250000 */  lw        $a1, ($s1)
/* 6A136C 8021A16C 26310004 */  addiu     $s1, $s1, 4
/* 6A1370 8021A170 0260202D */  daddu     $a0, $s3, $zero
/* 6A1374 8021A174 0C0B2026 */  jal       evt_set_variable
/* 6A1378 8021A178 2406016C */   addiu    $a2, $zero, 0x16c
/* 6A137C 8021A17C 0260202D */  daddu     $a0, $s3, $zero
/* 6A1380 8021A180 8E250000 */  lw        $a1, ($s1)
/* 6A1384 8021A184 2406004F */  addiu     $a2, $zero, 0x4f
.L8021A188:
/* 6A1388 8021A188 0C0B2026 */  jal       evt_set_variable
/* 6A138C 8021A18C 00000000 */   nop
.L8021A190:
/* 6A1390 8021A190 8FBF0038 */  lw        $ra, 0x38($sp)
/* 6A1394 8021A194 8FB50034 */  lw        $s5, 0x34($sp)
/* 6A1398 8021A198 8FB40030 */  lw        $s4, 0x30($sp)
/* 6A139C 8021A19C 8FB3002C */  lw        $s3, 0x2c($sp)
/* 6A13A0 8021A1A0 8FB20028 */  lw        $s2, 0x28($sp)
/* 6A13A4 8021A1A4 8FB10024 */  lw        $s1, 0x24($sp)
/* 6A13A8 8021A1A8 8FB00020 */  lw        $s0, 0x20($sp)
/* 6A13AC 8021A1AC 24020002 */  addiu     $v0, $zero, 2
/* 6A13B0 8021A1B0 03E00008 */  jr        $ra
/* 6A13B4 8021A1B4 27BD0040 */   addiu    $sp, $sp, 0x40
