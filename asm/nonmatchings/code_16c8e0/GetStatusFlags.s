.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetStatusFlags
/* 19DB10 8026F230 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19DB14 8026F234 AFB10014 */  sw        $s1, 0x14($sp)
/* 19DB18 8026F238 0080882D */  daddu     $s1, $a0, $zero
/* 19DB1C 8026F23C AFBF001C */  sw        $ra, 0x1c($sp)
/* 19DB20 8026F240 AFB20018 */  sw        $s2, 0x18($sp)
/* 19DB24 8026F244 AFB00010 */  sw        $s0, 0x10($sp)
/* 19DB28 8026F248 8E30000C */  lw        $s0, 0xc($s1)
/* 19DB2C 8026F24C 8E050000 */  lw        $a1, ($s0)
/* 19DB30 8026F250 0C0B1EAF */  jal       get_variable
/* 19DB34 8026F254 26100004 */   addiu    $s0, $s0, 4
/* 19DB38 8026F258 0040202D */  daddu     $a0, $v0, $zero
/* 19DB3C 8026F25C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19DB40 8026F260 14820002 */  bne       $a0, $v0, .L8026F26C
/* 19DB44 8026F264 8E120000 */   lw       $s2, ($s0)
/* 19DB48 8026F268 8E240148 */  lw        $a0, 0x148($s1)
.L8026F26C:
/* 19DB4C 8026F26C 0C09A75B */  jal       get_actor
/* 19DB50 8026F270 0000802D */   daddu    $s0, $zero, $zero
/* 19DB54 8026F274 0040202D */  daddu     $a0, $v0, $zero
/* 19DB58 8026F278 94820192 */  lhu       $v0, 0x192($a0)
/* 19DB5C 8026F27C 80830210 */  lb        $v1, 0x210($a0)
/* 19DB60 8026F280 10600020 */  beqz      $v1, .L8026F304
/* 19DB64 8026F284 30460700 */   andi     $a2, $v0, 0x700
/* 19DB68 8026F288 38620008 */  xori      $v0, $v1, 8
/* 19DB6C 8026F28C 2C420001 */  sltiu     $v0, $v0, 1
/* 19DB70 8026F290 00028540 */  sll       $s0, $v0, 0x15
/* 19DB74 8026F294 24020007 */  addiu     $v0, $zero, 7
/* 19DB78 8026F298 50620001 */  beql      $v1, $v0, .L8026F2A0
/* 19DB7C 8026F29C 36104000 */   ori      $s0, $s0, 0x4000
.L8026F2A0:
/* 19DB80 8026F2A0 24020006 */  addiu     $v0, $zero, 6
/* 19DB84 8026F2A4 50620001 */  beql      $v1, $v0, .L8026F2AC
/* 19DB88 8026F2A8 36101000 */   ori      $s0, $s0, 0x1000
.L8026F2AC:
/* 19DB8C 8026F2AC 24020005 */  addiu     $v0, $zero, 5
/* 19DB90 8026F2B0 14620004 */  bne       $v1, $v0, .L8026F2C4
/* 19DB94 8026F2B4 24020004 */   addiu    $v0, $zero, 4
/* 19DB98 8026F2B8 3C020001 */  lui       $v0, 1
/* 19DB9C 8026F2BC 02028025 */  or        $s0, $s0, $v0
/* 19DBA0 8026F2C0 24020004 */  addiu     $v0, $zero, 4
.L8026F2C4:
/* 19DBA4 8026F2C4 14620004 */  bne       $v1, $v0, .L8026F2D8
/* 19DBA8 8026F2C8 24020003 */   addiu    $v0, $zero, 3
/* 19DBAC 8026F2CC 3C020004 */  lui       $v0, 4
/* 19DBB0 8026F2D0 02028025 */  or        $s0, $s0, $v0
/* 19DBB4 8026F2D4 24020003 */  addiu     $v0, $zero, 3
.L8026F2D8:
/* 19DBB8 8026F2D8 50620001 */  beql      $v1, $v0, .L8026F2E0
/* 19DBBC 8026F2DC 36108000 */   ori      $s0, $s0, 0x8000
.L8026F2E0:
/* 19DBC0 8026F2E0 24020009 */  addiu     $v0, $zero, 9
/* 19DBC4 8026F2E4 14620004 */  bne       $v1, $v0, .L8026F2F8
/* 19DBC8 8026F2E8 2402000A */   addiu    $v0, $zero, 0xa
/* 19DBCC 8026F2EC 3C020002 */  lui       $v0, 2
/* 19DBD0 8026F2F0 02028025 */  or        $s0, $s0, $v0
/* 19DBD4 8026F2F4 2402000A */  addiu     $v0, $zero, 0xa
.L8026F2F8:
/* 19DBD8 8026F2F8 14620002 */  bne       $v1, $v0, .L8026F304
/* 19DBDC 8026F2FC 3C020008 */   lui      $v0, 8
/* 19DBE0 8026F300 02028025 */  or        $s0, $s0, $v0
.L8026F304:
/* 19DBE4 8026F304 80830212 */  lb        $v1, 0x212($a0)
/* 19DBE8 8026F308 10600003 */  beqz      $v1, .L8026F318
/* 19DBEC 8026F30C 2402000B */   addiu    $v0, $zero, 0xb
/* 19DBF0 8026F310 50620001 */  beql      $v1, $v0, .L8026F318
/* 19DBF4 8026F314 36102000 */   ori      $s0, $s0, 0x2000
.L8026F318:
/* 19DBF8 8026F318 80830214 */  lb        $v1, 0x214($a0)
/* 19DBFC 8026F31C 10600004 */  beqz      $v1, .L8026F330
/* 19DC00 8026F320 2402000C */   addiu    $v0, $zero, 0xc
/* 19DC04 8026F324 14620002 */  bne       $v1, $v0, .L8026F330
/* 19DC08 8026F328 3C020010 */   lui      $v0, 0x10
/* 19DC0C 8026F32C 02028025 */  or        $s0, $s0, $v0
.L8026F330:
/* 19DC10 8026F330 80830216 */  lb        $v1, 0x216($a0)
/* 19DC14 8026F334 10600004 */  beqz      $v1, .L8026F348
/* 19DC18 8026F338 2402000D */   addiu    $v0, $zero, 0xd
/* 19DC1C 8026F33C 14620002 */  bne       $v1, $v0, .L8026F348
/* 19DC20 8026F340 3C020100 */   lui      $v0, 0x100
/* 19DC24 8026F344 02028025 */  or        $s0, $s0, $v0
.L8026F348:
/* 19DC28 8026F348 80830218 */  lb        $v1, 0x218($a0)
/* 19DC2C 8026F34C 10600004 */  beqz      $v1, .L8026F360
/* 19DC30 8026F350 2402000E */   addiu    $v0, $zero, 0xe
/* 19DC34 8026F354 14620002 */  bne       $v1, $v0, .L8026F360
/* 19DC38 8026F358 3C020400 */   lui      $v0, 0x400
/* 19DC3C 8026F35C 02028025 */  or        $s0, $s0, $v0
.L8026F360:
/* 19DC40 8026F360 8C8301F4 */  lw        $v1, 0x1f4($a0)
/* 19DC44 8026F364 1060000D */  beqz      $v1, .L8026F39C
/* 19DC48 8026F368 24020100 */   addiu    $v0, $zero, 0x100
/* 19DC4C 8026F36C 3C050400 */  lui       $a1, 0x400
.L8026F370:
/* 19DC50 8026F370 8C620000 */  lw        $v0, ($v1)
/* 19DC54 8026F374 30420100 */  andi      $v0, $v0, 0x100
/* 19DC58 8026F378 54400001 */  bnel      $v0, $zero, .L8026F380
/* 19DC5C 8026F37C 02058025 */   or       $s0, $s0, $a1
.L8026F380:
/* 19DC60 8026F380 8C62007C */  lw        $v0, 0x7c($v1)
/* 19DC64 8026F384 30420020 */  andi      $v0, $v0, 0x20
/* 19DC68 8026F388 54400001 */  bnel      $v0, $zero, .L8026F390
/* 19DC6C 8026F38C 02058025 */   or       $s0, $s0, $a1
.L8026F390:
/* 19DC70 8026F390 8C63000C */  lw        $v1, 0xc($v1)
/* 19DC74 8026F394 1460FFF6 */  bnez      $v1, .L8026F370
/* 19DC78 8026F398 24020100 */   addiu    $v0, $zero, 0x100
.L8026F39C:
/* 19DC7C 8026F39C 10C20005 */  beq       $a2, $v0, .L8026F3B4
/* 19DC80 8026F3A0 28C20101 */   slti     $v0, $a2, 0x101
/* 19DC84 8026F3A4 10400009 */  beqz      $v0, .L8026F3CC
/* 19DC88 8026F3A8 00000000 */   nop      
/* 19DC8C 8026F3AC 14C00007 */  bnez      $a2, .L8026F3CC
/* 19DC90 8026F3B0 00000000 */   nop      
.L8026F3B4:
/* 19DC94 8026F3B4 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 19DC98 8026F3B8 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 19DC9C 8026F3BC 8042009A */  lb        $v0, 0x9a($v0)
/* 19DCA0 8026F3C0 10400002 */  beqz      $v0, .L8026F3CC
/* 19DCA4 8026F3C4 3C020400 */   lui      $v0, 0x400
/* 19DCA8 8026F3C8 02028025 */  or        $s0, $s0, $v0
.L8026F3CC:
/* 19DCAC 8026F3CC 80820220 */  lb        $v0, 0x220($a0)
/* 19DCB0 8026F3D0 10400002 */  beqz      $v0, .L8026F3DC
/* 19DCB4 8026F3D4 3C020200 */   lui      $v0, 0x200
/* 19DCB8 8026F3D8 02028025 */  or        $s0, $s0, $v0
.L8026F3DC:
/* 19DCBC 8026F3DC 80820221 */  lb        $v0, 0x221($a0)
/* 19DCC0 8026F3E0 10400002 */  beqz      $v0, .L8026F3EC
/* 19DCC4 8026F3E4 3C020800 */   lui      $v0, 0x800
/* 19DCC8 8026F3E8 02028025 */  or        $s0, $s0, $v0
.L8026F3EC:
/* 19DCCC 8026F3EC 80820222 */  lb        $v0, 0x222($a0)
/* 19DCD0 8026F3F0 10400002 */  beqz      $v0, .L8026F3FC
/* 19DCD4 8026F3F4 3C021000 */   lui      $v0, 0x1000
/* 19DCD8 8026F3F8 02028025 */  or        $s0, $s0, $v0
.L8026F3FC:
/* 19DCDC 8026F3FC 80820223 */  lb        $v0, 0x223($a0)
/* 19DCE0 8026F400 10400002 */  beqz      $v0, .L8026F40C
/* 19DCE4 8026F404 3C022000 */   lui      $v0, 0x2000
/* 19DCE8 8026F408 02028025 */  or        $s0, $s0, $v0
.L8026F40C:
/* 19DCEC 8026F40C 0C099CAB */  jal       heroes_is_ability_active
/* 19DCF0 8026F410 24050016 */   addiu    $a1, $zero, 0x16
/* 19DCF4 8026F414 10400002 */  beqz      $v0, .L8026F420
/* 19DCF8 8026F418 3C024000 */   lui      $v0, 0x4000
/* 19DCFC 8026F41C 02028025 */  or        $s0, $s0, $v0
.L8026F420:
/* 19DD00 8026F420 0220202D */  daddu     $a0, $s1, $zero
/* 19DD04 8026F424 0240282D */  daddu     $a1, $s2, $zero
/* 19DD08 8026F428 0C0B2026 */  jal       set_variable
/* 19DD0C 8026F42C 0200302D */   daddu    $a2, $s0, $zero
/* 19DD10 8026F430 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19DD14 8026F434 8FB20018 */  lw        $s2, 0x18($sp)
/* 19DD18 8026F438 8FB10014 */  lw        $s1, 0x14($sp)
/* 19DD1C 8026F43C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19DD20 8026F440 24020002 */  addiu     $v0, $zero, 2
/* 19DD24 8026F444 03E00008 */  jr        $ra
/* 19DD28 8026F448 27BD0020 */   addiu    $sp, $sp, 0x20
