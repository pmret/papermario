.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011EA54
/* B5154 8011EA54 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B5158 8011EA58 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B515C 8011EA5C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5160 8011EA60 AFBF001C */  sw        $ra, 0x1c($sp)
/* B5164 8011EA64 AFB20018 */  sw        $s2, 0x18($sp)
/* B5168 8011EA68 AFB10014 */  sw        $s1, 0x14($sp)
/* B516C 8011EA6C AFB00010 */  sw        $s0, 0x10($sp)
/* B5170 8011EA70 80420070 */  lb        $v0, 0x70($v0)
/* B5174 8011EA74 10400004 */  beqz      $v0, .L8011EA88
/* B5178 8011EA78 00A0882D */   daddu    $s1, $a1, $zero
/* B517C 8011EA7C 30820800 */  andi      $v0, $a0, 0x800
/* B5180 8011EA80 10400055 */  beqz      $v0, .L8011EBD8
/* B5184 8011EA84 00000000 */   nop
.L8011EA88:
/* B5188 8011EA88 2402F7FF */  addiu     $v0, $zero, -0x801
/* B518C 8011EA8C 00822024 */  and       $a0, $a0, $v0
/* B5190 8011EA90 3C038015 */  lui       $v1, %hi(gCurrentAnimMeshListPtr)
/* B5194 8011EA94 8C633A40 */  lw        $v1, %lo(gCurrentAnimMeshListPtr)($v1)
/* B5198 8011EA98 00041080 */  sll       $v0, $a0, 2
/* B519C 8011EA9C 00431021 */  addu      $v0, $v0, $v1
/* B51A0 8011EAA0 8C500000 */  lw        $s0, ($v0)
/* B51A4 8011EAA4 1200004C */  beqz      $s0, .L8011EBD8
/* B51A8 8011EAA8 00000000 */   nop
/* B51AC 8011EAAC 8E040000 */  lw        $a0, ($s0)
/* B51B0 8011EAB0 10800049 */  beqz      $a0, .L8011EBD8
/* B51B4 8011EAB4 3C020004 */   lui      $v0, 4
/* B51B8 8011EAB8 00821024 */  and       $v0, $a0, $v0
/* B51BC 8011EABC 14400046 */  bnez      $v0, .L8011EBD8
/* B51C0 8011EAC0 0000182D */   daddu    $v1, $zero, $zero
/* B51C4 8011EAC4 C6000090 */  lwc1      $f0, 0x90($s0)
/* B51C8 8011EAC8 C6020094 */  lwc1      $f2, 0x94($s0)
/* B51CC 8011EACC 2402FFBF */  addiu     $v0, $zero, -0x41
/* B51D0 8011EAD0 46020001 */  sub.s     $f0, $f0, $f2
/* B51D4 8011EAD4 44801000 */  mtc1      $zero, $f2
/* B51D8 8011EAD8 00821024 */  and       $v0, $a0, $v0
/* B51DC 8011EADC AE020000 */  sw        $v0, ($s0)
/* B51E0 8011EAE0 4602003E */  c.le.s    $f0, $f2
/* B51E4 8011EAE4 00000000 */  nop
/* B51E8 8011EAE8 45000014 */  bc1f      .L8011EB3C
/* B51EC 8011EAEC E6000090 */   swc1     $f0, 0x90($s0)
/* B51F0 8011EAF0 30428000 */  andi      $v0, $v0, 0x8000
/* B51F4 8011EAF4 14400008 */  bnez      $v0, .L8011EB18
/* B51F8 8011EAF8 0200202D */   daddu    $a0, $s0, $zero
.L8011EAFC:
/* B51FC 8011EAFC 0C047AFC */  jal       step_model_animator
/* B5200 8011EB00 0200202D */   daddu    $a0, $s0, $zero
/* B5204 8011EB04 0040182D */  daddu     $v1, $v0, $zero
/* B5208 8011EB08 1C60FFFC */  bgtz      $v1, .L8011EAFC
/* B520C 8011EB0C 2402FFFF */   addiu    $v0, $zero, -1
/* B5210 8011EB10 08047AD0 */  j         .L8011EB40
/* B5214 8011EB14 00000000 */   nop
.L8011EB18:
/* B5218 8011EB18 3C013F80 */  lui       $at, 0x3f80
/* B521C 8011EB1C 44810000 */  mtc1      $at, $f0
/* B5220 8011EB20 0C04819E */  jal       reload_mesh_animator_tree
/* B5224 8011EB24 E6000090 */   swc1     $f0, 0x90($s0)
.L8011EB28:
/* B5228 8011EB28 0C0481BE */  jal       step_mesh_animator
/* B522C 8011EB2C 0200202D */   daddu    $a0, $s0, $zero
/* B5230 8011EB30 0040182D */  daddu     $v1, $v0, $zero
/* B5234 8011EB34 1C60FFFC */  bgtz      $v1, .L8011EB28
/* B5238 8011EB38 00000000 */   nop
.L8011EB3C:
/* B523C 8011EB3C 2402FFFF */  addiu     $v0, $zero, -1
.L8011EB40:
/* B5240 8011EB40 10620025 */  beq       $v1, $v0, .L8011EBD8
/* B5244 8011EB44 0200202D */   daddu    $a0, $s0, $zero
/* B5248 8011EB48 0C047C16 */  jal       animator_update_model_transforms
/* B524C 8011EB4C 0220282D */   daddu    $a1, $s1, $zero
/* B5250 8011EB50 0000882D */  daddu     $s1, $zero, $zero
/* B5254 8011EB54 2412FFFF */  addiu     $s2, $zero, -1
/* B5258 8011EB58 3C108015 */  lui       $s0, %hi(D_801533C0)
/* B525C 8011EB5C 261033C0 */  addiu     $s0, $s0, %lo(D_801533C0)
.L8011EB60:
/* B5260 8011EB60 8E020000 */  lw        $v0, ($s0)
/* B5264 8011EB64 04420008 */  bltzl     $v0, .L8011EB88
/* B5268 8011EB68 26310001 */   addiu    $s1, $s1, 1
/* B526C 8011EB6C 2442FFFF */  addiu     $v0, $v0, -1
/* B5270 8011EB70 14400004 */  bnez      $v0, .L8011EB84
/* B5274 8011EB74 AE020000 */   sw       $v0, ($s0)
/* B5278 8011EB78 8E040004 */  lw        $a0, 4($s0)
/* B527C 8011EB7C 0C00AB1E */  jal       general_heap_free
/* B5280 8011EB80 AE120000 */   sw       $s2, ($s0)
.L8011EB84:
/* B5284 8011EB84 26310001 */  addiu     $s1, $s1, 1
.L8011EB88:
/* B5288 8011EB88 2A220060 */  slti      $v0, $s1, 0x60
/* B528C 8011EB8C 1440FFF4 */  bnez      $v0, .L8011EB60
/* B5290 8011EB90 26100008 */   addiu    $s0, $s0, 8
/* B5294 8011EB94 0000882D */  daddu     $s1, $zero, $zero
/* B5298 8011EB98 2412FFFF */  addiu     $s2, $zero, -1
/* B529C 8011EB9C 3C108015 */  lui       $s0, %hi(D_801536C0)
/* B52A0 8011EBA0 261036C0 */  addiu     $s0, $s0, %lo(D_801536C0)
.L8011EBA4:
/* B52A4 8011EBA4 8E020000 */  lw        $v0, ($s0)
/* B52A8 8011EBA8 04420008 */  bltzl     $v0, .L8011EBCC
/* B52AC 8011EBAC 26310001 */   addiu    $s1, $s1, 1
/* B52B0 8011EBB0 2442FFFF */  addiu     $v0, $v0, -1
/* B52B4 8011EBB4 14400004 */  bnez      $v0, .L8011EBC8
/* B52B8 8011EBB8 AE020000 */   sw       $v0, ($s0)
/* B52BC 8011EBBC 8E040004 */  lw        $a0, 4($s0)
/* B52C0 8011EBC0 0C00AB1E */  jal       general_heap_free
/* B52C4 8011EBC4 AE120000 */   sw       $s2, ($s0)
.L8011EBC8:
/* B52C8 8011EBC8 26310001 */  addiu     $s1, $s1, 1
.L8011EBCC:
/* B52CC 8011EBCC 2A220060 */  slti      $v0, $s1, 0x60
/* B52D0 8011EBD0 1440FFF4 */  bnez      $v0, .L8011EBA4
/* B52D4 8011EBD4 26100008 */   addiu    $s0, $s0, 8
.L8011EBD8:
/* B52D8 8011EBD8 8FBF001C */  lw        $ra, 0x1c($sp)
/* B52DC 8011EBDC 8FB20018 */  lw        $s2, 0x18($sp)
/* B52E0 8011EBE0 8FB10014 */  lw        $s1, 0x14($sp)
/* B52E4 8011EBE4 8FB00010 */  lw        $s0, 0x10($sp)
/* B52E8 8011EBE8 03E00008 */  jr        $ra
/* B52EC 8011EBEC 27BD0020 */   addiu    $sp, $sp, 0x20
