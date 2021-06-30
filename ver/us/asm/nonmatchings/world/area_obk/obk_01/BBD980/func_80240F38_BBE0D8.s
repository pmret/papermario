.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F38_BBE0D8
/* BBE0D8 80240F38 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BBE0DC 80240F3C AFB20018 */  sw        $s2, 0x18($sp)
/* BBE0E0 80240F40 0080902D */  daddu     $s2, $a0, $zero
/* BBE0E4 80240F44 AFBF001C */  sw        $ra, 0x1c($sp)
/* BBE0E8 80240F48 AFB10014 */  sw        $s1, 0x14($sp)
/* BBE0EC 80240F4C AFB00010 */  sw        $s0, 0x10($sp)
/* BBE0F0 80240F50 8E44014C */  lw        $a0, 0x14c($s2)
/* BBE0F4 80240F54 0C00EAD2 */  jal       get_npc_safe
/* BBE0F8 80240F58 00A0802D */   daddu    $s0, $a1, $zero
/* BBE0FC 80240F5C 12000002 */  beqz      $s0, .L80240F68
/* BBE100 80240F60 0040882D */   daddu    $s1, $v0, $zero
/* BBE104 80240F64 AE400074 */  sw        $zero, 0x74($s2)
.L80240F68:
/* BBE108 80240F68 8E430074 */  lw        $v1, 0x74($s2)
/* BBE10C 80240F6C 10600005 */  beqz      $v1, .L80240F84
/* BBE110 80240F70 24020001 */   addiu    $v0, $zero, 1
/* BBE114 80240F74 1062002C */  beq       $v1, $v0, .L80241028
/* BBE118 80240F78 00000000 */   nop
/* BBE11C 80240F7C 0809041E */  j         .L80241078
/* BBE120 80240F80 00000000 */   nop
.L80240F84:
/* BBE124 80240F84 0C00A67F */  jal       rand_int
/* BBE128 80240F88 24040064 */   addiu    $a0, $zero, 0x64
/* BBE12C 80240F8C 24040064 */  addiu     $a0, $zero, 0x64
/* BBE130 80240F90 244200B4 */  addiu     $v0, $v0, 0xb4
/* BBE134 80240F94 44820000 */  mtc1      $v0, $f0
/* BBE138 80240F98 00000000 */  nop
/* BBE13C 80240F9C 46800020 */  cvt.s.w   $f0, $f0
/* BBE140 80240FA0 0C00A67F */  jal       rand_int
/* BBE144 80240FA4 E6200040 */   swc1     $f0, 0x40($s1)
/* BBE148 80240FA8 2442FF38 */  addiu     $v0, $v0, -0xc8
/* BBE14C 80240FAC 44820000 */  mtc1      $v0, $f0
/* BBE150 80240FB0 00000000 */  nop
/* BBE154 80240FB4 46800020 */  cvt.s.w   $f0, $f0
/* BBE158 80240FB8 0C00A64D */  jal       rand_float
/* BBE15C 80240FBC E620003C */   swc1     $f0, 0x3c($s1)
/* BBE160 80240FC0 46000000 */  add.s     $f0, $f0, $f0
/* BBE164 80240FC4 3C014000 */  lui       $at, 0x4000
/* BBE168 80240FC8 44811000 */  mtc1      $at, $f2
/* BBE16C 80240FCC 00000000 */  nop
/* BBE170 80240FD0 46020000 */  add.s     $f0, $f0, $f2
/* BBE174 80240FD4 24040064 */  addiu     $a0, $zero, 0x64
/* BBE178 80240FD8 0C00A67F */  jal       rand_int
/* BBE17C 80240FDC E6200018 */   swc1     $f0, 0x18($s1)
/* BBE180 80240FE0 28420032 */  slti      $v0, $v0, 0x32
/* BBE184 80240FE4 10400007 */  beqz      $v0, .L80241004
/* BBE188 80240FE8 00000000 */   nop
/* BBE18C 80240FEC 3C014466 */  lui       $at, 0x4466
/* BBE190 80240FF0 44810000 */  mtc1      $at, $f0
/* BBE194 80240FF4 3C014387 */  lui       $at, 0x4387
/* BBE198 80240FF8 44811000 */  mtc1      $at, $f2
/* BBE19C 80240FFC 08090406 */  j         .L80241018
/* BBE1A0 80241000 E6200038 */   swc1     $f0, 0x38($s1)
.L80241004:
/* BBE1A4 80241004 3C01C1A0 */  lui       $at, 0xc1a0
/* BBE1A8 80241008 44810000 */  mtc1      $at, $f0
/* BBE1AC 8024100C 3C0142B4 */  lui       $at, 0x42b4
/* BBE1B0 80241010 44811000 */  mtc1      $at, $f2
/* BBE1B4 80241014 E6200038 */  swc1      $f0, 0x38($s1)
.L80241018:
/* BBE1B8 80241018 E622000C */  swc1      $f2, 0xc($s1)
/* BBE1BC 8024101C 24020001 */  addiu     $v0, $zero, 1
/* BBE1C0 80241020 0809041E */  j         .L80241078
/* BBE1C4 80241024 AE420074 */   sw       $v0, 0x74($s2)
.L80241028:
/* BBE1C8 80241028 8E250018 */  lw        $a1, 0x18($s1)
/* BBE1CC 8024102C 8E26000C */  lw        $a2, 0xc($s1)
/* BBE1D0 80241030 0C00EA95 */  jal       npc_move_heading
/* BBE1D4 80241034 0220202D */   daddu    $a0, $s1, $zero
/* BBE1D8 80241038 C6220038 */  lwc1      $f2, 0x38($s1)
/* BBE1DC 8024103C 3C01C1F0 */  lui       $at, 0xc1f0
/* BBE1E0 80241040 44810000 */  mtc1      $at, $f0
/* BBE1E4 80241044 00000000 */  nop
/* BBE1E8 80241048 4600103C */  c.lt.s    $f2, $f0
/* BBE1EC 8024104C 00000000 */  nop
/* BBE1F0 80241050 45030009 */  bc1tl     .L80241078
/* BBE1F4 80241054 AE400074 */   sw       $zero, 0x74($s2)
/* BBE1F8 80241058 3C014468 */  lui       $at, 0x4468
/* BBE1FC 8024105C 34218000 */  ori       $at, $at, 0x8000
/* BBE200 80241060 44810000 */  mtc1      $at, $f0
/* BBE204 80241064 00000000 */  nop
/* BBE208 80241068 4602003C */  c.lt.s    $f0, $f2
/* BBE20C 8024106C 00000000 */  nop
/* BBE210 80241070 45030001 */  bc1tl     .L80241078
/* BBE214 80241074 AE400074 */   sw       $zero, 0x74($s2)
.L80241078:
/* BBE218 80241078 8FBF001C */  lw        $ra, 0x1c($sp)
/* BBE21C 8024107C 8FB20018 */  lw        $s2, 0x18($sp)
/* BBE220 80241080 8FB10014 */  lw        $s1, 0x14($sp)
/* BBE224 80241084 8FB00010 */  lw        $s0, 0x10($sp)
/* BBE228 80241088 0000102D */  daddu     $v0, $zero, $zero
/* BBE22C 8024108C 03E00008 */  jr        $ra
/* BBE230 80241090 27BD0020 */   addiu    $sp, $sp, 0x20
