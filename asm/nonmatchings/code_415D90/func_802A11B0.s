.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802A11B0
/* 415F40 802A11B0 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 415F44 802A11B4 3C06800E */  lui   $a2, 0x800e
/* 415F48 802A11B8 24C6C070 */  addiu $a2, $a2, -0x3f90
/* 415F4C 802A11BC AFB00018 */  sw    $s0, 0x18($sp)
/* 415F50 802A11C0 3C10802B */  lui   $s0, 0x802b
/* 415F54 802A11C4 2610D000 */  addiu $s0, $s0, -0x3000
/* 415F58 802A11C8 AFBF0030 */  sw    $ra, 0x30($sp)
/* 415F5C 802A11CC AFB5002C */  sw    $s5, 0x2c($sp)
/* 415F60 802A11D0 AFB40028 */  sw    $s4, 0x28($sp)
/* 415F64 802A11D4 AFB30024 */  sw    $s3, 0x24($sp)
/* 415F68 802A11D8 AFB20020 */  sw    $s2, 0x20($sp)
/* 415F6C 802A11DC AFB1001C */  sw    $s1, 0x1c($sp)
/* 415F70 802A11E0 F7B60040 */  sdc1  $f22, 0x40($sp)
/* 415F74 802A11E4 F7B40038 */  sdc1  $f20, 0x38($sp)
/* 415F78 802A11E8 82030000 */  lb    $v1, ($s0)
/* 415F7C 802A11EC 2402000A */  addiu $v0, $zero, 0xa
/* 415F80 802A11F0 10620257 */  beq   $v1, $v0, .L802A1B50
/* 415F84 802A11F4 00000000 */   nop   
/* 415F88 802A11F8 2862000B */  slti  $v0, $v1, 0xb
/* 415F8C 802A11FC 50400010 */  beql  $v0, $zero, .L802A1240
/* 415F90 802A1200 2402001E */   addiu $v0, $zero, 0x1e
/* 415F94 802A1204 10600021 */  beqz  $v1, .L802A128C
/* 415F98 802A1208 24020036 */   addiu $v0, $zero, 0x36
/* 415F9C 802A120C 1C600006 */  bgtz  $v1, .L802A1228
/* 415FA0 802A1210 24050001 */   addiu $a1, $zero, 1
/* 415FA4 802A1214 2402FFFF */  addiu $v0, $zero, -1
/* 415FA8 802A1218 10620245 */  beq   $v1, $v0, .L802A1B30
/* 415FAC 802A121C 24030064 */   addiu $v1, $zero, 0x64
/* 415FB0 802A1220 080A870A */  j     .L802A1C28
/* 415FB4 802A1224 0000102D */   daddu $v0, $zero, $zero

.L802A1228:
/* 415FB8 802A1228 10650159 */  beq   $v1, $a1, .L802A1790
/* 415FBC 802A122C 24020002 */   addiu $v0, $zero, 2
/* 415FC0 802A1230 106201EC */  beq   $v1, $v0, .L802A19E4
/* 415FC4 802A1234 0000102D */   daddu $v0, $zero, $zero
/* 415FC8 802A1238 080A870A */  j     .L802A1C28
/* 415FCC 802A123C 00000000 */   nop   

.L802A1240:
/* 415FD0 802A1240 10620262 */  beq   $v1, $v0, .L802A1BCC
/* 415FD4 802A1244 24020003 */   addiu $v0, $zero, 3
/* 415FD8 802A1248 2862001F */  slti  $v0, $v1, 0x1f
/* 415FDC 802A124C 10400008 */  beqz  $v0, .L802A1270
/* 415FE0 802A1250 2402000B */   addiu $v0, $zero, 0xb
/* 415FE4 802A1254 10620248 */  beq   $v1, $v0, .L802A1B78
/* 415FE8 802A1258 00000000 */   nop   
/* 415FEC 802A125C 24020014 */  addiu $v0, $zero, 0x14
/* 415FF0 802A1260 1062024C */  beq   $v1, $v0, .L802A1B94
/* 415FF4 802A1264 24020003 */   addiu $v0, $zero, 3
/* 415FF8 802A1268 080A870A */  j     .L802A1C28
/* 415FFC 802A126C 0000102D */   daddu $v0, $zero, $zero

.L802A1270:
/* 416000 802A1270 24020064 */  addiu $v0, $zero, 0x64
/* 416004 802A1274 1062025C */  beq   $v1, $v0, .L802A1BE8
/* 416008 802A1278 24020065 */   addiu $v0, $zero, 0x65
/* 41600C 802A127C 10620260 */  beq   $v1, $v0, .L802A1C00
/* 416010 802A1280 0000102D */   daddu $v0, $zero, $zero
/* 416014 802A1284 080A870A */  j     .L802A1C28
/* 416018 802A1288 00000000 */   nop   

.L802A128C:
/* 41601C 802A128C 3C01802B */  lui   $at, 0x802b
/* 416020 802A1290 AC22D060 */  sw    $v0, -0x2fa0($at)
/* 416024 802A1294 240200AD */  addiu $v0, $zero, 0xad
/* 416028 802A1298 3C013E99 */  lui   $at, 0x3e99
/* 41602C 802A129C 3421999A */  ori   $at, $at, 0x999a
/* 416030 802A12A0 44810000 */  mtc1  $at, $f0
/* 416034 802A12A4 3C04802B */  lui   $a0, 0x802b
/* 416038 802A12A8 9084D0B3 */  lbu   $a0, -0x2f4d($a0)
/* 41603C 802A12AC 3C05802B */  lui   $a1, 0x802b
/* 416040 802A12B0 24A5D0AC */  addiu $a1, $a1, -0x2f54
/* 416044 802A12B4 3C01802B */  lui   $at, 0x802b
/* 416048 802A12B8 AC22D064 */  sw    $v0, -0x2f9c($at)
/* 41604C 802A12BC 3C01802B */  lui   $at, 0x802b
/* 416050 802A12C0 A020D004 */  sb    $zero, -0x2ffc($at)
/* 416054 802A12C4 3C01802B */  lui   $at, 0x802b
/* 416058 802A12C8 E420D070 */  swc1  $f0, -0x2f90($at)
/* 41605C 802A12CC 3C01802B */  lui   $at, 0x802b
/* 416060 802A12D0 A024D06B */  sb    $a0, -0x2f95($at)
/* 416064 802A12D4 90A20003 */  lbu   $v0, 3($a1)
/* 416068 802A12D8 00041823 */  negu  $v1, $a0
/* 41606C 802A12DC 3C01802B */  lui   $at, 0x802b
/* 416070 802A12E0 A023D069 */  sb    $v1, -0x2f97($at)
/* 416074 802A12E4 8CA30000 */  lw    $v1, ($a1)
/* 416078 802A12E8 2442FFFF */  addiu $v0, $v0, -1
/* 41607C 802A12EC 00441023 */  subu  $v0, $v0, $a0
/* 416080 802A12F0 3C01802B */  lui   $at, 0x802b
/* 416084 802A12F4 A022D06A */  sb    $v0, -0x2f96($at)
/* 416088 802A12F8 18600036 */  blez  $v1, .L802A13D4
/* 41608C 802A12FC 0000982D */   daddu $s3, $zero, $zero
/* 416090 802A1300 3C14802B */  lui   $s4, 0x802b
/* 416094 802A1304 2694D028 */  addiu $s4, $s4, -0x2fd8
/* 416098 802A1308 3C12802B */  lui   $s2, 0x802b
/* 41609C 802A130C 2652D010 */  addiu $s2, $s2, -0x2ff0
/* 4160A0 802A1310 3C10802B */  lui   $s0, 0x802b
/* 4160A4 802A1314 2610D078 */  addiu $s0, $s0, -0x2f88
.L802A1318:
/* 4160A8 802A1318 8E040000 */  lw    $a0, ($s0)
/* 4160AC 802A131C 26100004 */  addiu $s0, $s0, 4
/* 4160B0 802A1320 0C050529 */  jal   create_icon
/* 4160B4 802A1324 26730001 */   addiu $s3, $s3, 1
/* 4160B8 802A1328 0040882D */  daddu $s1, $v0, $zero
/* 4160BC 802A132C 0220202D */  daddu $a0, $s1, $zero
/* 4160C0 802A1330 24050005 */  addiu $a1, $zero, 5
/* 4160C4 802A1334 0C051277 */  jal   func_801449DC
/* 4160C8 802A1338 AE510000 */   sw    $s1, ($s2)
/* 4160CC 802A133C 0220202D */  daddu $a0, $s1, $zero
/* 4160D0 802A1340 0C051280 */  jal   set_icon_flags
/* 4160D4 802A1344 34058000 */   ori   $a1, $zero, 0x8000
/* 4160D8 802A1348 0220202D */  daddu $a0, $s1, $zero
/* 4160DC 802A134C 0C051280 */  jal   set_icon_flags
/* 4160E0 802A1350 24050080 */   addiu $a1, $zero, 0x80
/* 4160E4 802A1354 0220202D */  daddu $a0, $s1, $zero
/* 4160E8 802A1358 0C051280 */  jal   set_icon_flags
/* 4160EC 802A135C 24050002 */   addiu $a1, $zero, 2
/* 4160F0 802A1360 0220202D */  daddu $a0, $s1, $zero
/* 4160F4 802A1364 3C053F40 */  lui   $a1, 0x3f40
/* 4160F8 802A1368 0C051308 */  jal   func_80144C20
/* 4160FC 802A136C 26520004 */   addiu $s2, $s2, 4
/* 416100 802A1370 3C048029 */  lui   $a0, 0x8029
/* 416104 802A1374 24842C00 */  addiu $a0, $a0, 0x2c00
/* 416108 802A1378 0C050529 */  jal   create_icon
/* 41610C 802A137C 00000000 */   nop   
/* 416110 802A1380 0040882D */  daddu $s1, $v0, $zero
/* 416114 802A1384 0220202D */  daddu $a0, $s1, $zero
/* 416118 802A1388 0C0513F6 */  jal   func_80144FD8
/* 41611C 802A138C AE910000 */   sw    $s1, ($s4)
/* 416120 802A1390 0220202D */  daddu $a0, $s1, $zero
/* 416124 802A1394 0C051277 */  jal   func_801449DC
/* 416128 802A1398 2405000A */   addiu $a1, $zero, 0xa
/* 41612C 802A139C 0220202D */  daddu $a0, $s1, $zero
/* 416130 802A13A0 0C051280 */  jal   set_icon_flags
/* 416134 802A13A4 24050080 */   addiu $a1, $zero, 0x80
/* 416138 802A13A8 0220202D */  daddu $a0, $s1, $zero
/* 41613C 802A13AC 0C051280 */  jal   set_icon_flags
/* 416140 802A13B0 34058000 */   ori   $a1, $zero, 0x8000
/* 416144 802A13B4 0220202D */  daddu $a0, $s1, $zero
/* 416148 802A13B8 0C051280 */  jal   set_icon_flags
/* 41614C 802A13BC 24050002 */   addiu $a1, $zero, 2
/* 416150 802A13C0 3C02802B */  lui   $v0, 0x802b
/* 416154 802A13C4 8C42D0AC */  lw    $v0, -0x2f54($v0)
/* 416158 802A13C8 0262102A */  slt   $v0, $s3, $v0
/* 41615C 802A13CC 1440FFD2 */  bnez  $v0, .L802A1318
/* 416160 802A13D0 26940004 */   addiu $s4, $s4, 4
.L802A13D4:
/* 416164 802A13D4 3C048029 */  lui   $a0, 0x8029
/* 416168 802A13D8 24842C00 */  addiu $a0, $a0, 0x2c00
/* 41616C 802A13DC 0C050529 */  jal   create_icon
/* 416170 802A13E0 00000000 */   nop   
/* 416174 802A13E4 0040882D */  daddu $s1, $v0, $zero
/* 416178 802A13E8 3C01802B */  lui   $at, 0x802b
/* 41617C 802A13EC AC31D040 */  sw    $s1, -0x2fc0($at)
/* 416180 802A13F0 0C0513F6 */  jal   func_80144FD8
/* 416184 802A13F4 0220202D */   daddu $a0, $s1, $zero
/* 416188 802A13F8 0220202D */  daddu $a0, $s1, $zero
/* 41618C 802A13FC 0C051277 */  jal   func_801449DC
/* 416190 802A1400 24050007 */   addiu $a1, $zero, 7
/* 416194 802A1404 0220202D */  daddu $a0, $s1, $zero
/* 416198 802A1408 0C051280 */  jal   set_icon_flags
/* 41619C 802A140C 24050080 */   addiu $a1, $zero, 0x80
/* 4161A0 802A1410 0220202D */  daddu $a0, $s1, $zero
/* 4161A4 802A1414 0C051280 */  jal   set_icon_flags
/* 4161A8 802A1418 34058000 */   ori   $a1, $zero, 0x8000
/* 4161AC 802A141C 0220202D */  daddu $a0, $s1, $zero
/* 4161B0 802A1420 0C051280 */  jal   set_icon_flags
/* 4161B4 802A1424 24050002 */   addiu $a1, $zero, 2
/* 4161B8 802A1428 3C108029 */  lui   $s0, 0x8029
/* 4161BC 802A142C 26102BD8 */  addiu $s0, $s0, 0x2bd8
/* 4161C0 802A1430 0C050529 */  jal   create_icon
/* 4161C4 802A1434 0200202D */   daddu $a0, $s0, $zero
/* 4161C8 802A1438 0040882D */  daddu $s1, $v0, $zero
/* 4161CC 802A143C 3C01802B */  lui   $at, 0x802b
/* 4161D0 802A1440 AC31D044 */  sw    $s1, -0x2fbc($at)
/* 4161D4 802A1444 0C0513F6 */  jal   func_80144FD8
/* 4161D8 802A1448 0220202D */   daddu $a0, $s1, $zero
/* 4161DC 802A144C 0220202D */  daddu $a0, $s1, $zero
/* 4161E0 802A1450 0C051277 */  jal   func_801449DC
/* 4161E4 802A1454 0000282D */   daddu $a1, $zero, $zero
/* 4161E8 802A1458 0220202D */  daddu $a0, $s1, $zero
/* 4161EC 802A145C 24050028 */  addiu $a1, $zero, 0x28
/* 4161F0 802A1460 0C051261 */  jal   set_icon_render_pos
/* 4161F4 802A1464 240600D4 */   addiu $a2, $zero, 0xd4
/* 4161F8 802A1468 0220202D */  daddu $a0, $s1, $zero
/* 4161FC 802A146C 0000282D */  daddu $a1, $zero, $zero
/* 416200 802A1470 2406005B */  addiu $a2, $zero, 0x5b
/* 416204 802A1474 0C0513BF */  jal   func_80144EFC
/* 416208 802A1478 2407007F */   addiu $a3, $zero, 0x7f
/* 41620C 802A147C 0220202D */  daddu $a0, $s1, $zero
/* 416210 802A1480 24050010 */  addiu $a1, $zero, 0x10
/* 416214 802A1484 0C05149D */  jal   func_80145274
/* 416218 802A1488 2406FFF0 */   addiu $a2, $zero, -0x10
/* 41621C 802A148C 0220202D */  daddu $a0, $s1, $zero
/* 416220 802A1490 0C051280 */  jal   set_icon_flags
/* 416224 802A1494 24050080 */   addiu $a1, $zero, 0x80
/* 416228 802A1498 0220202D */  daddu $a0, $s1, $zero
/* 41622C 802A149C 0C05128B */  jal   clear_icon_flags
/* 416230 802A14A0 34058000 */   ori   $a1, $zero, 0x8000
/* 416234 802A14A4 0220202D */  daddu $a0, $s1, $zero
/* 416238 802A14A8 0C0513AC */  jal   func_80144EB0
/* 41623C 802A14AC 240500F0 */   addiu $a1, $zero, 0xf0
/* 416240 802A14B0 0C050529 */  jal   create_icon
/* 416244 802A14B4 0200202D */   daddu $a0, $s0, $zero
/* 416248 802A14B8 0040882D */  daddu $s1, $v0, $zero
/* 41624C 802A14BC 3C01802B */  lui   $at, 0x802b
/* 416250 802A14C0 AC31D048 */  sw    $s1, -0x2fb8($at)
/* 416254 802A14C4 0C0513F6 */  jal   func_80144FD8
/* 416258 802A14C8 0220202D */   daddu $a0, $s1, $zero
/* 41625C 802A14CC 0220202D */  daddu $a0, $s1, $zero
/* 416260 802A14D0 0C051277 */  jal   func_801449DC
/* 416264 802A14D4 24050002 */   addiu $a1, $zero, 2
/* 416268 802A14D8 0220202D */  daddu $a0, $s1, $zero
/* 41626C 802A14DC 24050027 */  addiu $a1, $zero, 0x27
/* 416270 802A14E0 0C051261 */  jal   set_icon_render_pos
/* 416274 802A14E4 240600D4 */   addiu $a2, $zero, 0xd4
/* 416278 802A14E8 0220202D */  daddu $a0, $s1, $zero
/* 41627C 802A14EC 0000282D */  daddu $a1, $zero, $zero
/* 416280 802A14F0 2406005B */  addiu $a2, $zero, 0x5b
/* 416284 802A14F4 0C0513BF */  jal   func_80144EFC
/* 416288 802A14F8 2407007F */   addiu $a3, $zero, 0x7f
/* 41628C 802A14FC 0220202D */  daddu $a0, $s1, $zero
/* 416290 802A1500 24050010 */  addiu $a1, $zero, 0x10
/* 416294 802A1504 0C05149D */  jal   func_80145274
/* 416298 802A1508 2406FFF0 */   addiu $a2, $zero, -0x10
/* 41629C 802A150C 0220202D */  daddu $a0, $s1, $zero
/* 4162A0 802A1510 0C051280 */  jal   set_icon_flags
/* 4162A4 802A1514 24050080 */   addiu $a1, $zero, 0x80
/* 4162A8 802A1518 0220202D */  daddu $a0, $s1, $zero
/* 4162AC 802A151C 0C05128B */  jal   clear_icon_flags
/* 4162B0 802A1520 34058000 */   ori   $a1, $zero, 0x8000
/* 4162B4 802A1524 0220202D */  daddu $a0, $s1, $zero
/* 4162B8 802A1528 0C0513AC */  jal   func_80144EB0
/* 4162BC 802A152C 240500F0 */   addiu $a1, $zero, 0xf0
/* 4162C0 802A1530 3C048029 */  lui   $a0, 0x8029
/* 4162C4 802A1534 24842C28 */  addiu $a0, $a0, 0x2c28
/* 4162C8 802A1538 0C050529 */  jal   create_icon
/* 4162CC 802A153C 00000000 */   nop   
/* 4162D0 802A1540 0040882D */  daddu $s1, $v0, $zero
/* 4162D4 802A1544 3C01802B */  lui   $at, 0x802b
/* 4162D8 802A1548 AC31D04C */  sw    $s1, -0x2fb4($at)
/* 4162DC 802A154C 0C0513F6 */  jal   func_80144FD8
/* 4162E0 802A1550 0220202D */   daddu $a0, $s1, $zero
/* 4162E4 802A1554 0220202D */  daddu $a0, $s1, $zero
/* 4162E8 802A1558 0C051277 */  jal   func_801449DC
/* 4162EC 802A155C 24050014 */   addiu $a1, $zero, 0x14
/* 4162F0 802A1560 0220202D */  daddu $a0, $s1, $zero
/* 4162F4 802A1564 2405004E */  addiu $a1, $zero, 0x4e
/* 4162F8 802A1568 0C051261 */  jal   set_icon_render_pos
/* 4162FC 802A156C 240600B2 */   addiu $a2, $zero, 0xb2
/* 416300 802A1570 0220202D */  daddu $a0, $s1, $zero
/* 416304 802A1574 240500FF */  addiu $a1, $zero, 0xff
/* 416308 802A1578 00A0302D */  daddu $a2, $a1, $zero
/* 41630C 802A157C 0C0513BF */  jal   func_80144EFC
/* 416310 802A1580 00A0382D */   daddu $a3, $a1, $zero
/* 416314 802A1584 0220202D */  daddu $a0, $s1, $zero
/* 416318 802A1588 0000282D */  daddu $a1, $zero, $zero
/* 41631C 802A158C 0C05149D */  jal   func_80145274
/* 416320 802A1590 00A0302D */   daddu $a2, $a1, $zero
/* 416324 802A1594 44800000 */  mtc1  $zero, $f0
/* 416328 802A1598 0220202D */  daddu $a0, $s1, $zero
/* 41632C 802A159C 44050000 */  mfc1  $a1, $f0
/* 416330 802A15A0 3C07C234 */  lui   $a3, 0xc234
/* 416334 802A15A4 0C051489 */  jal   func_80145224
/* 416338 802A15A8 00A0302D */   daddu $a2, $a1, $zero
/* 41633C 802A15AC 0220202D */  daddu $a0, $s1, $zero
/* 416340 802A15B0 0C0513AC */  jal   func_80144EB0
/* 416344 802A15B4 240500C8 */   addiu $a1, $zero, 0xc8
/* 416348 802A15B8 0220202D */  daddu $a0, $s1, $zero
/* 41634C 802A15BC 0C051280 */  jal   set_icon_flags
/* 416350 802A15C0 24050080 */   addiu $a1, $zero, 0x80
/* 416354 802A15C4 0220202D */  daddu $a0, $s1, $zero
/* 416358 802A15C8 0C051280 */  jal   set_icon_flags
/* 41635C 802A15CC 34058000 */   ori   $a1, $zero, 0x8000
/* 416360 802A15D0 0220202D */  daddu $a0, $s1, $zero
/* 416364 802A15D4 0C051280 */  jal   set_icon_flags
/* 416368 802A15D8 24050002 */   addiu $a1, $zero, 2
/* 41636C 802A15DC 3C048029 */  lui   $a0, 0x8029
/* 416370 802A15E0 24842CF4 */  addiu $a0, $a0, 0x2cf4
/* 416374 802A15E4 0C050529 */  jal   create_icon
/* 416378 802A15E8 00000000 */   nop   
/* 41637C 802A15EC 0040882D */  daddu $s1, $v0, $zero
/* 416380 802A15F0 0220202D */  daddu $a0, $s1, $zero
/* 416384 802A15F4 3C01802B */  lui   $at, 0x802b
/* 416388 802A15F8 AC31D05C */  sw    $s1, -0x2fa4($at)
/* 41638C 802A15FC 0C051277 */  jal   func_801449DC
/* 416390 802A1600 0000282D */   daddu $a1, $zero, $zero
/* 416394 802A1604 0220202D */  daddu $a0, $s1, $zero
/* 416398 802A1608 24050061 */  addiu $a1, $zero, 0x61
/* 41639C 802A160C 0C051261 */  jal   set_icon_render_pos
/* 4163A0 802A1610 240600D0 */   addiu $a2, $zero, 0xd0
/* 4163A4 802A1614 0220202D */  daddu $a0, $s1, $zero
/* 4163A8 802A1618 240500FF */  addiu $a1, $zero, 0xff
/* 4163AC 802A161C 00A0302D */  daddu $a2, $a1, $zero
/* 4163B0 802A1620 0C0513BF */  jal   func_80144EFC
/* 4163B4 802A1624 00A0382D */   daddu $a3, $a1, $zero
/* 4163B8 802A1628 0220202D */  daddu $a0, $s1, $zero
/* 4163BC 802A162C 0C051280 */  jal   set_icon_flags
/* 4163C0 802A1630 24050080 */   addiu $a1, $zero, 0x80
/* 4163C4 802A1634 0220202D */  daddu $a0, $s1, $zero
/* 4163C8 802A1638 0C05128B */  jal   clear_icon_flags
/* 4163CC 802A163C 34058000 */   ori   $a1, $zero, 0x8000
/* 4163D0 802A1640 0220202D */  daddu $a0, $s1, $zero
/* 4163D4 802A1644 0C0513AC */  jal   func_80144EB0
/* 4163D8 802A1648 240500E6 */   addiu $a1, $zero, 0xe6
/* 4163DC 802A164C 3C048029 */  lui   $a0, 0x8029
/* 4163E0 802A1650 24842C50 */  addiu $a0, $a0, 0x2c50
/* 4163E4 802A1654 0C050529 */  jal   create_icon
/* 4163E8 802A1658 00000000 */   nop   
/* 4163EC 802A165C 0040882D */  daddu $s1, $v0, $zero
/* 4163F0 802A1660 0220202D */  daddu $a0, $s1, $zero
/* 4163F4 802A1664 3C01802B */  lui   $at, 0x802b
/* 4163F8 802A1668 AC31D050 */  sw    $s1, -0x2fb0($at)
/* 4163FC 802A166C 0C051277 */  jal   func_801449DC
/* 416400 802A1670 24050005 */   addiu $a1, $zero, 5
/* 416404 802A1674 0220202D */  daddu $a0, $s1, $zero
/* 416408 802A1678 0C05128B */  jal   clear_icon_flags
/* 41640C 802A167C 34058000 */   ori   $a1, $zero, 0x8000
/* 416410 802A1680 0220202D */  daddu $a0, $s1, $zero
/* 416414 802A1684 0C051280 */  jal   set_icon_flags
/* 416418 802A1688 24050080 */   addiu $a1, $zero, 0x80
/* 41641C 802A168C 0220202D */  daddu $a0, $s1, $zero
/* 416420 802A1690 2405005E */  addiu $a1, $zero, 0x5e
/* 416424 802A1694 0C051261 */  jal   set_icon_render_pos
/* 416428 802A1698 240600D1 */   addiu $a2, $zero, 0xd1
/* 41642C 802A169C 3C048029 */  lui   $a0, 0x8029
/* 416430 802A16A0 24842C7C */  addiu $a0, $a0, 0x2c7c
/* 416434 802A16A4 0C050529 */  jal   create_icon
/* 416438 802A16A8 00000000 */   nop   
/* 41643C 802A16AC 0040882D */  daddu $s1, $v0, $zero
/* 416440 802A16B0 0220202D */  daddu $a0, $s1, $zero
/* 416444 802A16B4 3C01802B */  lui   $at, 0x802b
/* 416448 802A16B8 AC31D054 */  sw    $s1, -0x2fac($at)
/* 41644C 802A16BC 0C051277 */  jal   func_801449DC
/* 416450 802A16C0 24050005 */   addiu $a1, $zero, 5
/* 416454 802A16C4 0220202D */  daddu $a0, $s1, $zero
/* 416458 802A16C8 0C05128B */  jal   clear_icon_flags
/* 41645C 802A16CC 34058000 */   ori   $a1, $zero, 0x8000
/* 416460 802A16D0 0220202D */  daddu $a0, $s1, $zero
/* 416464 802A16D4 0C051280 */  jal   set_icon_flags
/* 416468 802A16D8 24050080 */   addiu $a1, $zero, 0x80
/* 41646C 802A16DC 0220202D */  daddu $a0, $s1, $zero
/* 416470 802A16E0 24050051 */  addiu $a1, $zero, 0x51
/* 416474 802A16E4 0C051261 */  jal   set_icon_render_pos
/* 416478 802A16E8 240600D2 */   addiu $a2, $zero, 0xd2
/* 41647C 802A16EC 3C048029 */  lui   $a0, 0x8029
/* 416480 802A16F0 24842CB8 */  addiu $a0, $a0, 0x2cb8
/* 416484 802A16F4 0C050529 */  jal   create_icon
/* 416488 802A16F8 00000000 */   nop   
/* 41648C 802A16FC 0040882D */  daddu $s1, $v0, $zero
/* 416490 802A1700 0220202D */  daddu $a0, $s1, $zero
/* 416494 802A1704 3C01802B */  lui   $at, 0x802b
/* 416498 802A1708 AC31D058 */  sw    $s1, -0x2fa8($at)
/* 41649C 802A170C 0C051277 */  jal   func_801449DC
/* 4164A0 802A1710 24050005 */   addiu $a1, $zero, 5
/* 4164A4 802A1714 0220202D */  daddu $a0, $s1, $zero
/* 4164A8 802A1718 0C05128B */  jal   clear_icon_flags
/* 4164AC 802A171C 34058000 */   ori   $a1, $zero, 0x8000
/* 4164B0 802A1720 0220202D */  daddu $a0, $s1, $zero
/* 4164B4 802A1724 0C051280 */  jal   set_icon_flags
/* 4164B8 802A1728 24050080 */   addiu $a1, $zero, 0x80
/* 4164BC 802A172C 0220202D */  daddu $a0, $s1, $zero
/* 4164C0 802A1730 24050066 */  addiu $a1, $zero, 0x66
/* 4164C4 802A1734 0C051261 */  jal   set_icon_render_pos
/* 4164C8 802A1738 240600D2 */   addiu $a2, $zero, 0xd2
/* 4164CC 802A173C 3C03802B */  lui   $v1, 0x802b
/* 4164D0 802A1740 8C63D100 */  lw    $v1, -0x2f00($v1)
/* 4164D4 802A1744 24020064 */  addiu $v0, $zero, 0x64
/* 4164D8 802A1748 3C01802B */  lui   $at, 0x802b
/* 4164DC 802A174C A422D00A */  sh    $v0, -0x2ff6($at)
/* 4164E0 802A1750 24020003 */  addiu $v0, $zero, 3
/* 4164E4 802A1754 3C01802B */  lui   $at, 0x802b
/* 4164E8 802A1758 A022D001 */  sb    $v0, -0x2fff($at)
/* 4164EC 802A175C 24020001 */  addiu $v0, $zero, 1
/* 4164F0 802A1760 3C01802B */  lui   $at, 0x802b
/* 4164F4 802A1764 A022D000 */  sb    $v0, -0x3000($at)
/* 4164F8 802A1768 000310C0 */  sll   $v0, $v1, 3
/* 4164FC 802A176C 00431023 */  subu  $v0, $v0, $v1
/* 416500 802A1770 00021080 */  sll   $v0, $v0, 2
/* 416504 802A1774 4482A000 */  mtc1  $v0, $f20
/* 416508 802A1778 00000000 */  nop   
/* 41650C 802A177C 4680A520 */  cvt.s.w $f20, $f20
/* 416510 802A1780 3C01802B */  lui   $at, 0x802b
/* 416514 802A1784 E434D06C */  swc1  $f20, -0x2f94($at)
/* 416518 802A1788 080A870A */  j     .L802A1C28
/* 41651C 802A178C 0000102D */   daddu $v0, $zero, $zero

.L802A1790:
/* 416520 802A1790 3C035555 */  lui   $v1, 0x5555
/* 416524 802A1794 3C10802B */  lui   $s0, 0x802b
/* 416528 802A1798 2610D001 */  addiu $s0, $s0, -0x2fff
/* 41652C 802A179C 82040000 */  lb    $a0, ($s0)
/* 416530 802A17A0 34635556 */  ori   $v1, $v1, 0x5556
/* 416534 802A17A4 00041040 */  sll   $v0, $a0, 1
/* 416538 802A17A8 00441021 */  addu  $v0, $v0, $a0
/* 41653C 802A17AC 000210C0 */  sll   $v0, $v0, 3
/* 416540 802A17B0 00441021 */  addu  $v0, $v0, $a0
/* 416544 802A17B4 00021080 */  sll   $v0, $v0, 2
/* 416548 802A17B8 00430018 */  mult  $v0, $v1
/* 41654C 802A17BC 000217C3 */  sra   $v0, $v0, 0x1f
/* 416550 802A17C0 00004010 */  mfhi  $t0
/* 416554 802A17C4 01021023 */  subu  $v0, $t0, $v0
/* 416558 802A17C8 3C01802B */  lui   $at, 0x802b
/* 41655C 802A17CC A422D00A */  sh    $v0, -0x2ff6($at)
/* 416560 802A17D0 1080000A */  beqz  $a0, .L802A17FC
/* 416564 802A17D4 00000000 */   nop   
/* 416568 802A17D8 14850005 */  bne   $a0, $a1, .L802A17F0
/* 41656C 802A17DC 00000000 */   nop   
/* 416570 802A17E0 3C04802B */  lui   $a0, 0x802b
/* 416574 802A17E4 8C84D04C */  lw    $a0, -0x2fb4($a0)
/* 416578 802A17E8 0C05128B */  jal   clear_icon_flags
/* 41657C 802A17EC 24050002 */   addiu $a1, $zero, 2
.L802A17F0:
/* 416580 802A17F0 92020000 */  lbu   $v0, ($s0)
/* 416584 802A17F4 080A8708 */  j     .L802A1C20
/* 416588 802A17F8 2442FFFF */   addiu $v0, $v0, -1

.L802A17FC:
/* 41658C 802A17FC 3C02802B */  lui   $v0, 0x802b
/* 416590 802A1800 8C42D100 */  lw    $v0, -0x2f00($v0)
/* 416594 802A1804 3C01802B */  lui   $at, 0x802b
/* 416598 802A1808 A020D002 */  sb    $zero, -0x2ffe($at)
/* 41659C 802A180C 3C01802B */  lui   $at, 0x802b
/* 4165A0 802A1810 A020D003 */  sb    $zero, -0x2ffd($at)
/* 4165A4 802A1814 000218C0 */  sll   $v1, $v0, 3
/* 4165A8 802A1818 00621823 */  subu  $v1, $v1, $v0
/* 4165AC 802A181C 00031880 */  sll   $v1, $v1, 2
/* 4165B0 802A1820 3C02802B */  lui   $v0, 0x802b
/* 4165B4 802A1824 8C42D0AC */  lw    $v0, -0x2f54($v0)
/* 4165B8 802A1828 4483A000 */  mtc1  $v1, $f20
/* 4165BC 802A182C 00000000 */  nop   
/* 4165C0 802A1830 4680A520 */  cvt.s.w $f20, $f20
/* 4165C4 802A1834 3C01802B */  lui   $at, 0x802b
/* 4165C8 802A1838 E434D06C */  swc1  $f20, -0x2f94($at)
/* 4165CC 802A183C 18400039 */  blez  $v0, .L802A1924
/* 4165D0 802A1840 0000982D */   daddu $s3, $zero, $zero
/* 4165D4 802A1844 4480B000 */  mtc1  $zero, $f22
/* 4165D8 802A1848 3C15802B */  lui   $s5, 0x802b
/* 4165DC 802A184C 26B5D028 */  addiu $s5, $s5, -0x2fd8
/* 4165E0 802A1850 3C14802B */  lui   $s4, 0x802b
/* 4165E4 802A1854 2694D010 */  addiu $s4, $s4, -0x2ff0
.L802A1858:
/* 4165E8 802A1858 27A40010 */  addiu $a0, $sp, 0x10
/* 4165EC 802A185C 27A50014 */  addiu $a1, $sp, 0x14
/* 4165F0 802A1860 3C0642AE */  lui   $a2, 0x42ae
/* 4165F4 802A1864 4407A000 */  mfc1  $a3, $f20
/* 4165F8 802A1868 26730001 */  addiu $s3, $s3, 1
/* 4165FC 802A186C E7B60010 */  swc1  $f22, 0x10($sp)
/* 416600 802A1870 0C00A7E7 */  jal   add_vec2D_polar
/* 416604 802A1874 E7B60014 */   swc1  $f22, 0x14($sp)
/* 416608 802A1878 8E910000 */  lw    $s1, ($s4)
/* 41660C 802A187C 26940004 */  addiu $s4, $s4, 4
/* 416610 802A1880 3C01802B */  lui   $at, 0x802b
/* 416614 802A1884 C422D060 */  lwc1  $f2, -0x2fa0($at)
/* 416618 802A1888 468010A0 */  cvt.s.w $f2, $f2
/* 41661C 802A188C C7A00010 */  lwc1  $f0, 0x10($sp)
/* 416620 802A1890 C7A40014 */  lwc1  $f4, 0x14($sp)
/* 416624 802A1894 46001080 */  add.s $f2, $f2, $f0
/* 416628 802A1898 0220202D */  daddu $a0, $s1, $zero
/* 41662C 802A189C 3C01802B */  lui   $at, 0x802b
/* 416630 802A18A0 C420D064 */  lwc1  $f0, -0x2f9c($at)
/* 416634 802A18A4 46800020 */  cvt.s.w $f0, $f0
/* 416638 802A18A8 46040000 */  add.s $f0, $f0, $f4
/* 41663C 802A18AC 4600118D */  trunc.w.s $f6, $f2
/* 416640 802A18B0 44123000 */  mfc1  $s2, $f6
/* 416644 802A18B4 00000000 */  nop   
/* 416648 802A18B8 0240282D */  daddu $a1, $s2, $zero
/* 41664C 802A18BC 4600018D */  trunc.w.s $f6, $f0
/* 416650 802A18C0 44103000 */  mfc1  $s0, $f6
/* 416654 802A18C4 0C051261 */  jal   set_icon_render_pos
/* 416658 802A18C8 0200302D */   daddu $a2, $s0, $zero
/* 41665C 802A18CC 0220202D */  daddu $a0, $s1, $zero
/* 416660 802A18D0 0C05128B */  jal   clear_icon_flags
/* 416664 802A18D4 24050002 */   addiu $a1, $zero, 2
/* 416668 802A18D8 0240282D */  daddu $a1, $s2, $zero
/* 41666C 802A18DC 0200302D */  daddu $a2, $s0, $zero
/* 416670 802A18E0 8EB10000 */  lw    $s1, ($s5)
/* 416674 802A18E4 26B50004 */  addiu $s5, $s5, 4
/* 416678 802A18E8 0C051261 */  jal   set_icon_render_pos
/* 41667C 802A18EC 0220202D */   daddu $a0, $s1, $zero
/* 416680 802A18F0 0220202D */  daddu $a0, $s1, $zero
/* 416684 802A18F4 0C0513AC */  jal   func_80144EB0
/* 416688 802A18F8 24050064 */   addiu $a1, $zero, 0x64
/* 41668C 802A18FC 0220202D */  daddu $a0, $s1, $zero
/* 416690 802A1900 0C05128B */  jal   clear_icon_flags
/* 416694 802A1904 24050002 */   addiu $a1, $zero, 2
/* 416698 802A1908 3C02802B */  lui   $v0, 0x802b
/* 41669C 802A190C 8C42D0AC */  lw    $v0, -0x2f54($v0)
/* 4166A0 802A1910 3C0141E0 */  lui   $at, 0x41e0
/* 4166A4 802A1914 44810000 */  mtc1  $at, $f0
/* 4166A8 802A1918 0262102A */  slt   $v0, $s3, $v0
/* 4166AC 802A191C 1440FFCE */  bnez  $v0, .L802A1858
/* 4166B0 802A1920 4600A500 */   add.s $f20, $f20, $f0
.L802A1924:
/* 4166B4 802A1924 27A40010 */  addiu $a0, $sp, 0x10
/* 4166B8 802A1928 3C03802B */  lui   $v1, 0x802b
/* 4166BC 802A192C 8C63D100 */  lw    $v1, -0x2f00($v1)
/* 4166C0 802A1930 3C0642AE */  lui   $a2, 0x42ae
/* 4166C4 802A1934 000310C0 */  sll   $v0, $v1, 3
/* 4166C8 802A1938 00431023 */  subu  $v0, $v0, $v1
/* 4166CC 802A193C 00021080 */  sll   $v0, $v0, 2
/* 4166D0 802A1940 44823000 */  mtc1  $v0, $f6
/* 4166D4 802A1944 00000000 */  nop   
/* 4166D8 802A1948 468031A0 */  cvt.s.w $f6, $f6
/* 4166DC 802A194C 44073000 */  mfc1  $a3, $f6
/* 4166E0 802A1950 27A50014 */  addiu $a1, $sp, 0x14
/* 4166E4 802A1954 AFA00010 */  sw    $zero, 0x10($sp)
/* 4166E8 802A1958 0C00A7E7 */  jal   add_vec2D_polar
/* 4166EC 802A195C AFA00014 */   sw    $zero, 0x14($sp)
/* 4166F0 802A1960 3C01802B */  lui   $at, 0x802b
/* 4166F4 802A1964 C422D060 */  lwc1  $f2, -0x2fa0($at)
/* 4166F8 802A1968 468010A0 */  cvt.s.w $f2, $f2
/* 4166FC 802A196C C7A00010 */  lwc1  $f0, 0x10($sp)
/* 416700 802A1970 3C11802B */  lui   $s1, 0x802b
/* 416704 802A1974 8E31D040 */  lw    $s1, -0x2fc0($s1)
/* 416708 802A1978 46001080 */  add.s $f2, $f2, $f0
/* 41670C 802A197C C7A40014 */  lwc1  $f4, 0x14($sp)
/* 416710 802A1980 3C01802B */  lui   $at, 0x802b
/* 416714 802A1984 C420D064 */  lwc1  $f0, -0x2f9c($at)
/* 416718 802A1988 46800020 */  cvt.s.w $f0, $f0
/* 41671C 802A198C 46040000 */  add.s $f0, $f0, $f4
/* 416720 802A1990 4600118D */  trunc.w.s $f6, $f2
/* 416724 802A1994 44053000 */  mfc1  $a1, $f6
/* 416728 802A1998 4600018D */  trunc.w.s $f6, $f0
/* 41672C 802A199C 44063000 */  mfc1  $a2, $f6
/* 416730 802A19A0 0C051261 */  jal   set_icon_render_pos
/* 416734 802A19A4 0220202D */   daddu $a0, $s1, $zero
/* 416738 802A19A8 0220202D */  daddu $a0, $s1, $zero
/* 41673C 802A19AC 0C0513AC */  jal   func_80144EB0
/* 416740 802A19B0 240500B4 */   addiu $a1, $zero, 0xb4
/* 416744 802A19B4 3C053F59 */  lui   $a1, 0x3f59
/* 416748 802A19B8 34A5999A */  ori   $a1, $a1, 0x999a
/* 41674C 802A19BC 0C051308 */  jal   func_80144C20
/* 416750 802A19C0 0220202D */   daddu $a0, $s1, $zero
/* 416754 802A19C4 0220202D */  daddu $a0, $s1, $zero
/* 416758 802A19C8 0C05128B */  jal   clear_icon_flags
/* 41675C 802A19CC 24050002 */   addiu $a1, $zero, 2
/* 416760 802A19D0 24020002 */  addiu $v0, $zero, 2
/* 416764 802A19D4 3C01802B */  lui   $at, 0x802b
/* 416768 802A19D8 A022D000 */  sb    $v0, -0x3000($at)
/* 41676C 802A19DC 080A870A */  j     .L802A1C28
/* 416770 802A19E0 0000102D */   daddu $v0, $zero, $zero

.L802A19E4:
/* 416774 802A19E4 8CC20214 */  lw    $v0, 0x214($a2)
/* 416778 802A19E8 30428000 */  andi  $v0, $v0, 0x8000
/* 41677C 802A19EC 10400021 */  beqz  $v0, .L802A1A74
/* 416780 802A19F0 00000000 */   nop   
/* 416784 802A19F4 3C11802B */  lui   $s1, 0x802b
/* 416788 802A19F8 2631D002 */  addiu $s1, $s1, -0x2ffe
/* 41678C 802A19FC 3C12802B */  lui   $s2, 0x802b
/* 416790 802A1A00 2652D06B */  addiu $s2, $s2, -0x2f95
/* 416794 802A1A04 82220000 */  lb    $v0, ($s1)
/* 416798 802A1A08 82430000 */  lb    $v1, ($s2)
/* 41679C 802A1A0C 00431021 */  addu  $v0, $v0, $v1
/* 4167A0 802A1A10 00021080 */  sll   $v0, $v0, 2
/* 4167A4 802A1A14 3C01802B */  lui   $at, 0x802b
/* 4167A8 802A1A18 00220821 */  addu  $at, $at, $v0
/* 4167AC 802A1A1C 8C22D0D0 */  lw    $v0, -0x2f30($at)
/* 4167B0 802A1A20 14450005 */  bne   $v0, $a1, .L802A1A38
/* 4167B4 802A1A24 00000000 */   nop   
/* 4167B8 802A1A28 0C05272D */  jal   play_sound
/* 4167BC 802A1A2C 240400C9 */   addiu $a0, $zero, 0xc9
/* 4167C0 802A1A30 080A8708 */  j     .L802A1C20
/* 4167C4 802A1A34 2402FFFF */   addiu $v0, $zero, -1

.L802A1A38:
/* 4167C8 802A1A38 0C05272D */  jal   play_sound
/* 4167CC 802A1A3C 2404021D */   addiu $a0, $zero, 0x21d
/* 4167D0 802A1A40 82220000 */  lb    $v0, ($s1)
/* 4167D4 802A1A44 82430000 */  lb    $v1, ($s2)
/* 4167D8 802A1A48 00431021 */  addu  $v0, $v0, $v1
/* 4167DC 802A1A4C 00021080 */  sll   $v0, $v0, 2
/* 4167E0 802A1A50 3C03802B */  lui   $v1, 0x802b
/* 4167E4 802A1A54 00621821 */  addu  $v1, $v1, $v0
/* 4167E8 802A1A58 9063D0EB */  lbu   $v1, -0x2f15($v1)
/* 4167EC 802A1A5C 24020064 */  addiu $v0, $zero, 0x64
/* 4167F0 802A1A60 A2020000 */  sb    $v0, ($s0)
/* 4167F4 802A1A64 3C01802B */  lui   $at, 0x802b
/* 4167F8 802A1A68 A023D068 */  sb    $v1, -0x2f98($at)
/* 4167FC 802A1A6C 080A870A */  j     .L802A1C28
/* 416800 802A1A70 0000102D */   daddu $v0, $zero, $zero

.L802A1A74:
/* 416804 802A1A74 3C05802B */  lui   $a1, 0x802b
/* 416808 802A1A78 24A5D002 */  addiu $a1, $a1, -0x2ffe
/* 41680C 802A1A7C 90A40000 */  lbu   $a0, ($a1)
/* 416810 802A1A80 3C02802B */  lui   $v0, 0x802b
/* 416814 802A1A84 8042D004 */  lb    $v0, -0x2ffc($v0)
/* 416818 802A1A88 3C01802B */  lui   $at, 0x802b
/* 41681C 802A1A8C A024D003 */  sb    $a0, -0x2ffd($at)
/* 416820 802A1A90 1440001B */  bnez  $v0, .L802A1B00
/* 416824 802A1A94 3C030005 */   lui   $v1, 5
/* 416828 802A1A98 8CC20218 */  lw    $v0, 0x218($a2)
/* 41682C 802A1A9C 00431024 */  and   $v0, $v0, $v1
/* 416830 802A1AA0 10400008 */  beqz  $v0, .L802A1AC4
/* 416834 802A1AA4 00041600 */   sll   $v0, $a0, 0x18
/* 416838 802A1AA8 3C03802B */  lui   $v1, 0x802b
/* 41683C 802A1AAC 8063D069 */  lb    $v1, -0x2f97($v1)
/* 416840 802A1AB0 00021603 */  sra   $v0, $v0, 0x18
/* 416844 802A1AB4 0062182A */  slt   $v1, $v1, $v0
/* 416848 802A1AB8 10600002 */  beqz  $v1, .L802A1AC4
/* 41684C 802A1ABC 2482FFFF */   addiu $v0, $a0, -1
/* 416850 802A1AC0 A0A20000 */  sb    $v0, ($a1)
.L802A1AC4:
/* 416854 802A1AC4 8CC20218 */  lw    $v0, 0x218($a2)
/* 416858 802A1AC8 3C03000A */  lui   $v1, 0xa
/* 41685C 802A1ACC 00431024 */  and   $v0, $v0, $v1
/* 416860 802A1AD0 1040000B */  beqz  $v0, .L802A1B00
/* 416864 802A1AD4 00000000 */   nop   
/* 416868 802A1AD8 3C04802B */  lui   $a0, 0x802b
/* 41686C 802A1ADC 2484D002 */  addiu $a0, $a0, -0x2ffe
/* 416870 802A1AE0 80820000 */  lb    $v0, ($a0)
/* 416874 802A1AE4 3C03802B */  lui   $v1, 0x802b
/* 416878 802A1AE8 8063D06A */  lb    $v1, -0x2f96($v1)
/* 41687C 802A1AEC 0043102A */  slt   $v0, $v0, $v1
/* 416880 802A1AF0 90830000 */  lbu   $v1, ($a0)
/* 416884 802A1AF4 10400002 */  beqz  $v0, .L802A1B00
/* 416888 802A1AF8 24620001 */   addiu $v0, $v1, 1
/* 41688C 802A1AFC A0820000 */  sb    $v0, ($a0)
.L802A1B00:
/* 416890 802A1B00 3C03802B */  lui   $v1, 0x802b
/* 416894 802A1B04 8063D003 */  lb    $v1, -0x2ffd($v1)
/* 416898 802A1B08 3C02802B */  lui   $v0, 0x802b
/* 41689C 802A1B0C 8042D002 */  lb    $v0, -0x2ffe($v0)
/* 4168A0 802A1B10 10620044 */  beq   $v1, $v0, .L802A1C24
/* 4168A4 802A1B14 24020001 */   addiu $v0, $zero, 1
/* 4168A8 802A1B18 3C01802B */  lui   $at, 0x802b
/* 4168AC 802A1B1C A022D004 */  sb    $v0, -0x2ffc($at)
/* 4168B0 802A1B20 0C05272D */  jal   play_sound
/* 4168B4 802A1B24 240400C8 */   addiu $a0, $zero, 0xc8
/* 4168B8 802A1B28 080A870A */  j     .L802A1C28
/* 4168BC 802A1B2C 0000102D */   daddu $v0, $zero, $zero

.L802A1B30:
/* 4168C0 802A1B30 3C02802B */  lui   $v0, 0x802b
/* 4168C4 802A1B34 8042D002 */  lb    $v0, -0x2ffe($v0)
/* 4168C8 802A1B38 3C04802B */  lui   $a0, 0x802b
/* 4168CC 802A1B3C 8084D06B */  lb    $a0, -0x2f95($a0)
/* 4168D0 802A1B40 3C01802B */  lui   $at, 0x802b
/* 4168D4 802A1B44 A423D008 */  sh    $v1, -0x2ff8($at)
/* 4168D8 802A1B48 080A86F1 */  j     .L802A1BC4
/* 4168DC 802A1B4C 00441021 */   addu  $v0, $v0, $a0

.L802A1B50:
/* 4168E0 802A1B50 3C02802B */  lui   $v0, 0x802b
/* 4168E4 802A1B54 8042D002 */  lb    $v0, -0x2ffe($v0)
/* 4168E8 802A1B58 3C04802B */  lui   $a0, 0x802b
/* 4168EC 802A1B5C 8084D06B */  lb    $a0, -0x2f95($a0)
/* 4168F0 802A1B60 3C01802B */  lui   $at, 0x802b
/* 4168F4 802A1B64 A020D001 */  sb    $zero, -0x2fff($at)
/* 4168F8 802A1B68 3C01802B */  lui   $at, 0x802b
/* 4168FC 802A1B6C A420D006 */  sh    $zero, -0x2ffa($at)
/* 416900 802A1B70 080A86EF */  j     .L802A1BBC
/* 416904 802A1B74 2403000B */   addiu $v1, $zero, 0xb

.L802A1B78:
/* 416908 802A1B78 3C02802B */  lui   $v0, 0x802b
/* 41690C 802A1B7C 8042D002 */  lb    $v0, -0x2ffe($v0)
/* 416910 802A1B80 3C03802B */  lui   $v1, 0x802b
/* 416914 802A1B84 8063D06B */  lb    $v1, -0x2f95($v1)
/* 416918 802A1B88 00431021 */  addu  $v0, $v0, $v1
/* 41691C 802A1B8C 080A870A */  j     .L802A1C28
/* 416920 802A1B90 24420001 */   addiu $v0, $v0, 1

.L802A1B94:
/* 416924 802A1B94 3C01802B */  lui   $at, 0x802b
/* 416928 802A1B98 A022D001 */  sb    $v0, -0x2fff($at)
/* 41692C 802A1B9C 240200FF */  addiu $v0, $zero, 0xff
/* 416930 802A1BA0 3C01802B */  lui   $at, 0x802b
/* 416934 802A1BA4 A422D006 */  sh    $v0, -0x2ffa($at)
/* 416938 802A1BA8 3C02802B */  lui   $v0, 0x802b
/* 41693C 802A1BAC 8042D002 */  lb    $v0, -0x2ffe($v0)
/* 416940 802A1BB0 3C04802B */  lui   $a0, 0x802b
/* 416944 802A1BB4 8084D06B */  lb    $a0, -0x2f95($a0)
/* 416948 802A1BB8 24030002 */  addiu $v1, $zero, 2
.L802A1BBC:
/* 41694C 802A1BBC A2030000 */  sb    $v1, ($s0)
/* 416950 802A1BC0 00441021 */  addu  $v0, $v0, $a0
.L802A1BC4:
/* 416954 802A1BC4 080A870A */  j     .L802A1C28
/* 416958 802A1BC8 24420001 */   addiu $v0, $v0, 1

.L802A1BCC:
/* 41695C 802A1BCC 3C01802B */  lui   $at, 0x802b
/* 416960 802A1BD0 A022D001 */  sb    $v0, -0x2fff($at)
/* 416964 802A1BD4 240200FF */  addiu $v0, $zero, 0xff
/* 416968 802A1BD8 3C01802B */  lui   $at, 0x802b
/* 41696C 802A1BDC A422D006 */  sh    $v0, -0x2ffa($at)
/* 416970 802A1BE0 080A8708 */  j     .L802A1C20
/* 416974 802A1BE4 2402FFFF */   addiu $v0, $zero, -1

.L802A1BE8:
/* 416978 802A1BE8 3C04802B */  lui   $a0, 0x802b
/* 41697C 802A1BEC 8084D068 */  lb    $a0, -0x2f98($a0)
/* 416980 802A1BF0 0C093E58 */  jal   show_battle_message
/* 416984 802A1BF4 2405005A */   addiu $a1, $zero, 0x5a
/* 416988 802A1BF8 080A8708 */  j     .L802A1C20
/* 41698C 802A1BFC 24020065 */   addiu $v0, $zero, 0x65

.L802A1C00:
/* 416990 802A1C00 0C093EAD */  jal   is_popup_displayed
/* 416994 802A1C04 00000000 */   nop   
/* 416998 802A1C08 14400007 */  bnez  $v0, .L802A1C28
/* 41699C 802A1C0C 0000102D */   daddu $v0, $zero, $zero
/* 4169A0 802A1C10 2402FFFF */  addiu $v0, $zero, -1
/* 4169A4 802A1C14 3C01802B */  lui   $at, 0x802b
/* 4169A8 802A1C18 A022D068 */  sb    $v0, -0x2f98($at)
/* 4169AC 802A1C1C 24020002 */  addiu $v0, $zero, 2
.L802A1C20:
/* 4169B0 802A1C20 A2020000 */  sb    $v0, ($s0)
.L802A1C24:
/* 4169B4 802A1C24 0000102D */  daddu $v0, $zero, $zero
.L802A1C28:
/* 4169B8 802A1C28 8FBF0030 */  lw    $ra, 0x30($sp)
/* 4169BC 802A1C2C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 4169C0 802A1C30 8FB40028 */  lw    $s4, 0x28($sp)
/* 4169C4 802A1C34 8FB30024 */  lw    $s3, 0x24($sp)
/* 4169C8 802A1C38 8FB20020 */  lw    $s2, 0x20($sp)
/* 4169CC 802A1C3C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 4169D0 802A1C40 8FB00018 */  lw    $s0, 0x18($sp)
/* 4169D4 802A1C44 D7B60040 */  ldc1  $f22, 0x40($sp)
/* 4169D8 802A1C48 D7B40038 */  ldc1  $f20, 0x38($sp)
/* 4169DC 802A1C4C 03E00008 */  jr    $ra
/* 4169E0 802A1C50 27BD0048 */   addiu $sp, $sp, 0x48

