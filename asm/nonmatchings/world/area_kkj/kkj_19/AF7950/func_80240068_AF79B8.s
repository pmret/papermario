.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240068_AF79B8
/* AF79B8 80240068 3C028024 */  lui       $v0, %hi(D_80240E88_AF87D8)
/* AF79BC 8024006C 8C420E88 */  lw        $v0, %lo(D_80240E88_AF87D8)($v0)
/* AF79C0 80240070 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF79C4 80240074 AFBF0014 */  sw        $ra, 0x14($sp)
/* AF79C8 80240078 10400005 */  beqz      $v0, .L80240090
/* AF79CC 8024007C AFB00010 */   sw       $s0, 0x10($sp)
/* AF79D0 80240080 3C108014 */  lui       $s0, %hi(D_80147474)
/* AF79D4 80240084 26107474 */  addiu     $s0, $s0, %lo(D_80147474)
/* AF79D8 80240088 08090027 */  j         .L8024009C
/* AF79DC 8024008C 2404000A */   addiu    $a0, $zero, 0xa
.L80240090:
/* AF79E0 80240090 2404000A */  addiu     $a0, $zero, 0xa
/* AF79E4 80240094 3C108014 */  lui       $s0, %hi(D_80147574)
/* AF79E8 80240098 26107574 */  addiu     $s0, $s0, %lo(D_80147574)
.L8024009C:
/* AF79EC 8024009C 0C051F9F */  jal       set_window_update
/* AF79F0 802400A0 0200282D */   daddu    $a1, $s0, $zero
/* AF79F4 802400A4 2404000B */  addiu     $a0, $zero, 0xb
/* AF79F8 802400A8 0C051F9F */  jal       set_window_update
/* AF79FC 802400AC 0200282D */   daddu    $a1, $s0, $zero
/* AF7A00 802400B0 3C038024 */  lui       $v1, %hi(D_80240E8C_AF87DC)
/* AF7A04 802400B4 24630E8C */  addiu     $v1, $v1, %lo(D_80240E8C_AF87DC)
/* AF7A08 802400B8 8C620000 */  lw        $v0, ($v1)
/* AF7A0C 802400BC 18400003 */  blez      $v0, .L802400CC
/* AF7A10 802400C0 2442FFFF */   addiu    $v0, $v0, -1
/* AF7A14 802400C4 08090035 */  j         .L802400D4
/* AF7A18 802400C8 AC620000 */   sw       $v0, ($v1)
.L802400CC:
/* AF7A1C 802400CC 3C018024 */  lui       $at, %hi(D_80240E88_AF87D8)
/* AF7A20 802400D0 AC200E88 */  sw        $zero, %lo(D_80240E88_AF87D8)($at)
.L802400D4:
/* AF7A24 802400D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* AF7A28 802400D8 8FB00010 */  lw        $s0, 0x10($sp)
/* AF7A2C 802400DC 03E00008 */  jr        $ra
/* AF7A30 802400E0 27BD0018 */   addiu    $sp, $sp, 0x18
