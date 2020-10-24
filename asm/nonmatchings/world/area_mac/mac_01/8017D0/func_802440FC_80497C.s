.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802440FC_80497C
/* 80497C 802440FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 804980 80244100 AFB00018 */  sw        $s0, 0x18($sp)
/* 804984 80244104 0080802D */  daddu     $s0, $a0, $zero
/* 804988 80244108 10A00022 */  beqz      $a1, .L80244194
/* 80498C 8024410C AFBF001C */   sw       $ra, 0x1c($sp)
/* 804990 80244110 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 804994 80244114 2404002B */   addiu    $a0, $zero, 0x2b
/* 804998 80244118 0C046B4C */  jal       get_model_from_list_index
/* 80499C 8024411C 0040202D */   daddu    $a0, $v0, $zero
/* 8049A0 80244120 0040202D */  daddu     $a0, $v0, $zero
/* 8049A4 80244124 2405FFFF */  addiu     $a1, $zero, -1
/* 8049A8 80244128 0C046F1F */  jal       func_8011BC7C
/* 8049AC 8024412C 24060003 */   addiu    $a2, $zero, 3
/* 8049B0 80244130 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8049B4 80244134 2404002A */   addiu    $a0, $zero, 0x2a
/* 8049B8 80244138 0C046B4C */  jal       get_model_from_list_index
/* 8049BC 8024413C 0040202D */   daddu    $a0, $v0, $zero
/* 8049C0 80244140 0040202D */  daddu     $a0, $v0, $zero
/* 8049C4 80244144 2405FFFF */  addiu     $a1, $zero, -1
/* 8049C8 80244148 0C046F1F */  jal       func_8011BC7C
/* 8049CC 8024414C 24060003 */   addiu    $a2, $zero, 3
/* 8049D0 80244150 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 8049D4 80244154 24040029 */   addiu    $a0, $zero, 0x29
/* 8049D8 80244158 0C046B4C */  jal       get_model_from_list_index
/* 8049DC 8024415C 0040202D */   daddu    $a0, $v0, $zero
/* 8049E0 80244160 0040202D */  daddu     $a0, $v0, $zero
/* 8049E4 80244164 2405FFFF */  addiu     $a1, $zero, -1
/* 8049E8 80244168 0C046F1F */  jal       func_8011BC7C
/* 8049EC 8024416C 24060003 */   addiu    $a2, $zero, 3
/* 8049F0 80244170 240400FF */  addiu     $a0, $zero, 0xff
/* 8049F4 80244174 0080282D */  daddu     $a1, $a0, $zero
/* 8049F8 80244178 0080302D */  daddu     $a2, $a0, $zero
/* 8049FC 8024417C 0000382D */  daddu     $a3, $zero, $zero
/* 804A00 80244180 AFA00010 */  sw        $zero, 0x10($sp)
/* 804A04 80244184 0C046FE6 */  jal       func_8011BF98
/* 804A08 80244188 AFA00014 */   sw       $zero, 0x14($sp)
/* 804A0C 8024418C 240200FF */  addiu     $v0, $zero, 0xff
/* 804A10 80244190 AE020070 */  sw        $v0, 0x70($s0)
.L80244194:
/* 804A14 80244194 8E020070 */  lw        $v0, 0x70($s0)
/* 804A18 80244198 2442FFFC */  addiu     $v0, $v0, -4
/* 804A1C 8024419C AE020070 */  sw        $v0, 0x70($s0)
/* 804A20 802441A0 28420040 */  slti      $v0, $v0, 0x40
/* 804A24 802441A4 10400002 */  beqz      $v0, .L802441B0
/* 804A28 802441A8 24020040 */   addiu    $v0, $zero, 0x40
/* 804A2C 802441AC AE020070 */  sw        $v0, 0x70($s0)
.L802441B0:
/* 804A30 802441B0 92040073 */  lbu       $a0, 0x73($s0)
/* 804A34 802441B4 0000382D */  daddu     $a3, $zero, $zero
/* 804A38 802441B8 AFA00010 */  sw        $zero, 0x10($sp)
/* 804A3C 802441BC AFA00014 */  sw        $zero, 0x14($sp)
/* 804A40 802441C0 0080282D */  daddu     $a1, $a0, $zero
/* 804A44 802441C4 0C046FE6 */  jal       func_8011BF98
/* 804A48 802441C8 0080302D */   daddu    $a2, $a0, $zero
/* 804A4C 802441CC 8E020070 */  lw        $v0, 0x70($s0)
/* 804A50 802441D0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 804A54 802441D4 8FB00018 */  lw        $s0, 0x18($sp)
/* 804A58 802441D8 38420040 */  xori      $v0, $v0, 0x40
/* 804A5C 802441DC 2C420001 */  sltiu     $v0, $v0, 1
/* 804A60 802441E0 00021040 */  sll       $v0, $v0, 1
/* 804A64 802441E4 03E00008 */  jr        $ra
/* 804A68 802441E8 27BD0020 */   addiu    $sp, $sp, 0x20
