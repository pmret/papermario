.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_load_npc_sprite
/* 1011DC 802DE0EC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1011E0 802DE0F0 AFB50024 */  sw        $s5, 0x24($sp)
/* 1011E4 802DE0F4 00A0A82D */  daddu     $s5, $a1, $zero
/* 1011E8 802DE0F8 00041403 */  sra       $v0, $a0, 0x10
/* 1011EC 802DE0FC AFB40020 */  sw        $s4, 0x20($sp)
/* 1011F0 802DE100 30547FFF */  andi      $s4, $v0, 0x7fff
/* 1011F4 802DE104 000437C2 */  srl       $a2, $a0, 0x1f
/* 1011F8 802DE108 0000202D */  daddu     $a0, $zero, $zero
/* 1011FC 802DE10C AFB3001C */  sw        $s3, 0x1c($sp)
/* 101200 802DE110 3C13802E */  lui       $s3, %hi(D_802DFA48)
/* 101204 802DE114 2673FA48 */  addiu     $s3, $s3, %lo(D_802DFA48)
/* 101208 802DE118 0260182D */  daddu     $v1, $s3, $zero
/* 10120C 802DE11C AFBF0028 */  sw        $ra, 0x28($sp)
/* 101210 802DE120 AFB20018 */  sw        $s2, 0x18($sp)
/* 101214 802DE124 AFB10014 */  sw        $s1, 0x14($sp)
/* 101218 802DE128 AFB00010 */  sw        $s0, 0x10($sp)
.L802DE12C:
/* 10121C 802DE12C 8C620000 */  lw        $v0, ($v1)
/* 101220 802DE130 10400005 */  beqz      $v0, .L802DE148
/* 101224 802DE134 00000000 */   nop
/* 101228 802DE138 24840001 */  addiu     $a0, $a0, 1
/* 10122C 802DE13C 28820033 */  slti      $v0, $a0, 0x33
/* 101230 802DE140 1440FFFA */  bnez      $v0, .L802DE12C
/* 101234 802DE144 24630014 */   addiu    $v1, $v1, 0x14
.L802DE148:
/* 101238 802DE148 3C03802E */  lui       $v1, %hi(D_802DF530)
/* 10123C 802DE14C 2463F530 */  addiu     $v1, $v1, %lo(D_802DF530)
/* 101240 802DE150 8C620000 */  lw        $v0, ($v1)
/* 101244 802DE154 0044102A */  slt       $v0, $v0, $a0
/* 101248 802DE158 54400001 */  bnel      $v0, $zero, .L802DE160
/* 10124C 802DE15C AC640000 */   sw       $a0, ($v1)
.L802DE160:
/* 101250 802DE160 24020033 */  addiu     $v0, $zero, 0x33
/* 101254 802DE164 14820003 */  bne       $a0, $v0, .L802DE174
/* 101258 802DE168 00141880 */   sll      $v1, $s4, 2
/* 10125C 802DE16C 080B78A2 */  j         .L802DE288
/* 101260 802DE170 2402FFFF */   addiu    $v0, $zero, -1
.L802DE174:
/* 101264 802DE174 3C02802E */  lui       $v0, %hi(spr_npcSprites)
/* 101268 802DE178 2442F5B0 */  addiu     $v0, $v0, %lo(spr_npcSprites)
/* 10126C 802DE17C 00628821 */  addu      $s1, $v1, $v0
/* 101270 802DE180 8E220000 */  lw        $v0, ($s1)
/* 101274 802DE184 1040000E */  beqz      $v0, .L802DE1C0
/* 101278 802DE188 0080902D */   daddu    $s2, $a0, $zero
/* 10127C 802DE18C 3C03802E */  lui       $v1, %hi(spr_npcSpriteInstanceCount)
/* 101280 802DE190 2463F958 */  addiu     $v1, $v1, %lo(spr_npcSpriteInstanceCount)
/* 101284 802DE194 02831821 */  addu      $v1, $s4, $v1
/* 101288 802DE198 90620000 */  lbu       $v0, ($v1)
/* 10128C 802DE19C 24420001 */  addiu     $v0, $v0, 1
/* 101290 802DE1A0 A0620000 */  sb        $v0, ($v1)
/* 101294 802DE1A4 00121080 */  sll       $v0, $s2, 2
/* 101298 802DE1A8 00521021 */  addu      $v0, $v0, $s2
/* 10129C 802DE1AC 00021080 */  sll       $v0, $v0, 2
/* 1012A0 802DE1B0 8E300000 */  lw        $s0, ($s1)
/* 1012A4 802DE1B4 00531021 */  addu      $v0, $v0, $s3
/* 1012A8 802DE1B8 080B7882 */  j         .L802DE208
/* 1012AC 802DE1BC AC500008 */   sw       $s0, 8($v0)
.L802DE1C0:
/* 1012B0 802DE1C0 2684FFFF */  addiu     $a0, $s4, -1
/* 1012B4 802DE1C4 24020001 */  addiu     $v0, $zero, 1
/* 1012B8 802DE1C8 3C01802E */  lui       $at, %hi(spr_npcSpriteInstanceCount)
/* 1012BC 802DE1CC 00340821 */  addu      $at, $at, $s4
/* 1012C0 802DE1D0 A022F958 */  sb        $v0, %lo(spr_npcSpriteInstanceCount)($at)
/* 1012C4 802DE1D4 0C0B7AC3 */  jal       spr_load_sprite
/* 1012C8 802DE1D8 0000282D */   daddu    $a1, $zero, $zero
/* 1012CC 802DE1DC 0040802D */  daddu     $s0, $v0, $zero
/* 1012D0 802DE1E0 00121080 */  sll       $v0, $s2, 2
/* 1012D4 802DE1E4 00521021 */  addu      $v0, $v0, $s2
/* 1012D8 802DE1E8 00021080 */  sll       $v0, $v0, 2
/* 1012DC 802DE1EC 00531021 */  addu      $v0, $v0, $s3
/* 1012E0 802DE1F0 AC500008 */  sw        $s0, 8($v0)
/* 1012E4 802DE1F4 12A00004 */  beqz      $s5, .L802DE208
/* 1012E8 802DE1F8 AE300000 */   sw       $s0, ($s1)
/* 1012EC 802DE1FC 0200202D */  daddu     $a0, $s0, $zero
/* 1012F0 802DE200 0C0B7C03 */  jal       spr_load_npc_extra_anims
/* 1012F4 802DE204 02A0282D */   daddu    $a1, $s5, $zero
.L802DE208:
/* 1012F8 802DE208 8E040008 */  lw        $a0, 8($s0)
/* 1012FC 802DE20C 0C0B7CB6 */  jal       spr_allocate_components
/* 101300 802DE210 00000000 */   nop
/* 101304 802DE214 0040882D */  daddu     $s1, $v0, $zero
/* 101308 802DE218 00121080 */  sll       $v0, $s2, 2
/* 10130C 802DE21C 00521021 */  addu      $v0, $v0, $s2
/* 101310 802DE220 00021080 */  sll       $v0, $v0, 2
/* 101314 802DE224 3C01802E */  lui       $at, %hi(D_802DFA4C)
/* 101318 802DE228 00220821 */  addu      $at, $at, $v0
/* 10131C 802DE22C AC31FA4C */  sw        $s1, %lo(D_802DFA4C)($at)
/* 101320 802DE230 8E230000 */  lw        $v1, ($s1)
/* 101324 802DE234 2402FFFF */  addiu     $v0, $zero, -1
/* 101328 802DE238 10620009 */  beq       $v1, $v0, .L802DE260
/* 10132C 802DE23C 0040982D */   daddu    $s3, $v0, $zero
.L802DE240:
/* 101330 802DE240 8E300000 */  lw        $s0, ($s1)
/* 101334 802DE244 0C04E9C1 */  jal       func_8013A704
/* 101338 802DE248 24040001 */   addiu    $a0, $zero, 1
/* 10133C 802DE24C 26310004 */  addiu     $s1, $s1, 4
/* 101340 802DE250 AE02004C */  sw        $v0, 0x4c($s0)
/* 101344 802DE254 8E220000 */  lw        $v0, ($s1)
/* 101348 802DE258 1453FFF9 */  bne       $v0, $s3, .L802DE240
/* 10134C 802DE25C 00000000 */   nop
.L802DE260:
/* 101350 802DE260 0240102D */  daddu     $v0, $s2, $zero
/* 101354 802DE264 3C03802E */  lui       $v1, %hi(D_802DFA48)
/* 101358 802DE268 2463FA48 */  addiu     $v1, $v1, %lo(D_802DFA48)
/* 10135C 802DE26C 00022080 */  sll       $a0, $v0, 2
/* 101360 802DE270 00822021 */  addu      $a0, $a0, $v0
/* 101364 802DE274 00042080 */  sll       $a0, $a0, 2
/* 101368 802DE278 00832021 */  addu      $a0, $a0, $v1
/* 10136C 802DE27C 2403FFFF */  addiu     $v1, $zero, -1
/* 101370 802DE280 AC940000 */  sw        $s4, ($a0)
/* 101374 802DE284 AC83000C */  sw        $v1, 0xc($a0)
.L802DE288:
/* 101378 802DE288 8FBF0028 */  lw        $ra, 0x28($sp)
/* 10137C 802DE28C 8FB50024 */  lw        $s5, 0x24($sp)
/* 101380 802DE290 8FB40020 */  lw        $s4, 0x20($sp)
/* 101384 802DE294 8FB3001C */  lw        $s3, 0x1c($sp)
/* 101388 802DE298 8FB20018 */  lw        $s2, 0x18($sp)
/* 10138C 802DE29C 8FB10014 */  lw        $s1, 0x14($sp)
/* 101390 802DE2A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 101394 802DE2A4 03E00008 */  jr        $ra
/* 101398 802DE2A8 27BD0030 */   addiu    $sp, $sp, 0x30
