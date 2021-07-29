.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218058_4B1248
/* 4B1248 80218058 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B124C 8021805C AFB10014 */  sw        $s1, 0x14($sp)
/* 4B1250 80218060 0080882D */  daddu     $s1, $a0, $zero
/* 4B1254 80218064 AFBF001C */  sw        $ra, 0x1c($sp)
/* 4B1258 80218068 AFB20018 */  sw        $s2, 0x18($sp)
/* 4B125C 8021806C AFB00010 */  sw        $s0, 0x10($sp)
/* 4B1260 80218070 8E30000C */  lw        $s0, 0xc($s1)
/* 4B1264 80218074 8E050000 */  lw        $a1, ($s0)
/* 4B1268 80218078 0C0B1EAF */  jal       get_variable
/* 4B126C 8021807C 26100004 */   addiu    $s0, $s0, 4
/* 4B1270 80218080 8E050000 */  lw        $a1, ($s0)
/* 4B1274 80218084 26100004 */  addiu     $s0, $s0, 4
/* 4B1278 80218088 0220202D */  daddu     $a0, $s1, $zero
/* 4B127C 8021808C 0C0B1EAF */  jal       get_variable
/* 4B1280 80218090 0040902D */   daddu    $s2, $v0, $zero
/* 4B1284 80218094 0220202D */  daddu     $a0, $s1, $zero
/* 4B1288 80218098 8E050000 */  lw        $a1, ($s0)
/* 4B128C 8021809C 0C0B1EAF */  jal       get_variable
/* 4B1290 802180A0 0040802D */   daddu    $s0, $v0, $zero
/* 4B1294 802180A4 0040882D */  daddu     $s1, $v0, $zero
/* 4B1298 802180A8 2402FFFF */  addiu     $v0, $zero, -1
/* 4B129C 802180AC 16020005 */  bne       $s0, $v0, .L802180C4
/* 4B12A0 802180B0 24020001 */   addiu    $v0, $zero, 1
/* 4B12A4 802180B4 0C04760B */  jal       mdl_set_all_fog_mode
/* 4B12A8 802180B8 0220202D */   daddu    $a0, $s1, $zero
/* 4B12AC 802180BC 08086059 */  j         .L80218164
/* 4B12B0 802180C0 24020002 */   addiu    $v0, $zero, 2
.L802180C4:
/* 4B12B4 802180C4 12420018 */  beq       $s2, $v0, .L80218128
/* 4B12B8 802180C8 2A420002 */   slti     $v0, $s2, 2
/* 4B12BC 802180CC 10400005 */  beqz      $v0, .L802180E4
/* 4B12C0 802180D0 24020002 */   addiu    $v0, $zero, 2
/* 4B12C4 802180D4 12400007 */  beqz      $s2, .L802180F4
/* 4B12C8 802180D8 3412FFFF */   ori      $s2, $zero, 0xffff
/* 4B12CC 802180DC 08086059 */  j         .L80218164
/* 4B12D0 802180E0 00000000 */   nop
.L802180E4:
/* 4B12D4 802180E4 1242001B */  beq       $s2, $v0, .L80218154
/* 4B12D8 802180E8 24020002 */   addiu    $v0, $zero, 2
/* 4B12DC 802180EC 08086059 */  j         .L80218164
/* 4B12E0 802180F0 00000000 */   nop
.L802180F4:
/* 4B12E4 802180F4 8E040000 */  lw        $a0, ($s0)
/* 4B12E8 802180F8 1092001A */  beq       $a0, $s2, .L80218164
/* 4B12EC 802180FC 24020002 */   addiu    $v0, $zero, 2
/* 4B12F0 80218100 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 4B12F4 80218104 26100004 */   addiu    $s0, $s0, 4
/* 4B12F8 80218108 0C046B4C */  jal       get_model_from_list_index
/* 4B12FC 8021810C 0040202D */   daddu    $a0, $v0, $zero
/* 4B1300 80218110 0040202D */  daddu     $a0, $v0, $zero
/* 4B1304 80218114 2405FFFF */  addiu     $a1, $zero, -1
/* 4B1308 80218118 0C046F1F */  jal       set_mdl_custom_gfx_set
/* 4B130C 8021811C 0220302D */   daddu    $a2, $s1, $zero
/* 4B1310 80218120 0808603D */  j         .L802180F4
/* 4B1314 80218124 00000000 */   nop
.L80218128:
/* 4B1318 80218128 3412FFFF */  ori       $s2, $zero, 0xffff
.L8021812C:
/* 4B131C 8021812C 8E020000 */  lw        $v0, ($s0)
/* 4B1320 80218130 1052000B */  beq       $v0, $s2, .L80218160
/* 4B1324 80218134 2405FFFF */   addiu    $a1, $zero, -1
/* 4B1328 80218138 96040002 */  lhu       $a0, 2($s0)
/* 4B132C 8021813C 0220302D */  daddu     $a2, $s1, $zero
/* 4B1330 80218140 26100004 */  addiu     $s0, $s0, 4
/* 4B1334 80218144 0C046E54 */  jal       func_8011B950
/* 4B1338 80218148 0000382D */   daddu    $a3, $zero, $zero
/* 4B133C 8021814C 0808604B */  j         .L8021812C
/* 4B1340 80218150 00000000 */   nop
.L80218154:
/* 4B1344 80218154 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 4B1348 80218158 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 4B134C 8021815C A0510000 */  sb        $s1, ($v0)
.L80218160:
/* 4B1350 80218160 24020002 */  addiu     $v0, $zero, 2
.L80218164:
/* 4B1354 80218164 8FBF001C */  lw        $ra, 0x1c($sp)
/* 4B1358 80218168 8FB20018 */  lw        $s2, 0x18($sp)
/* 4B135C 8021816C 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B1360 80218170 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B1364 80218174 03E00008 */  jr        $ra
/* 4B1368 80218178 27BD0020 */   addiu    $sp, $sp, 0x20
