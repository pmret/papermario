.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A4D0
/* D0BD0 8013A4D0 3C028007 */  lui       $v0, 0x8007
/* D0BD4 8013A4D4 8C4241F4 */  lw        $v0, 0x41f4($v0)
/* D0BD8 8013A4D8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D0BDC 8013A4DC AFB00010 */  sw        $s0, 0x10($sp)
/* D0BE0 8013A4E0 3C108015 */  lui       $s0, %hi(D_80156954)
/* D0BE4 8013A4E4 26106954 */  addiu     $s0, $s0, %lo(D_80156954)
/* D0BE8 8013A4E8 AFBF0024 */  sw        $ra, 0x24($sp)
/* D0BEC 8013A4EC AFB40020 */  sw        $s4, 0x20($sp)
/* D0BF0 8013A4F0 AFB3001C */  sw        $s3, 0x1c($sp)
/* D0BF4 8013A4F4 AFB20018 */  sw        $s2, 0x18($sp)
/* D0BF8 8013A4F8 AFB10014 */  sw        $s1, 0x14($sp)
/* D0BFC 8013A4FC 8E040000 */  lw        $a0, ($s0)
/* D0C00 8013A500 00021080 */  sll       $v0, $v0, 2
/* D0C04 8013A504 3C018015 */  lui       $at, 0x8015
/* D0C08 8013A508 00220821 */  addu      $at, $at, $v0
/* D0C0C 8013A50C 8C226948 */  lw        $v0, 0x6948($at)
/* D0C10 8013A510 3C018015 */  lui       $at, 0x8015
/* D0C14 8013A514 A420EE14 */  sh        $zero, -0x11ec($at)
/* D0C18 8013A518 3C018015 */  lui       $at, 0x8015
/* D0C1C 8013A51C AC226950 */  sw        $v0, 0x6950($at)
/* D0C20 8013A520 0C04EA7A */  jal       func_8013A9E8
/* D0C24 8013A524 24110001 */   addiu    $s1, $zero, 1
/* D0C28 8013A528 8E030000 */  lw        $v1, ($s0)
/* D0C2C 8013A52C 24120005 */  addiu     $s2, $zero, 5
/* D0C30 8013A530 8C620014 */  lw        $v0, 0x14($v1)
/* D0C34 8013A534 2410007C */  addiu     $s0, $zero, 0x7c
/* D0C38 8013A538 00511025 */  or        $v0, $v0, $s1
/* D0C3C 8013A53C AC620014 */  sw        $v0, 0x14($v1)
.L8013A540:
/* D0C40 8013A540 3C028015 */  lui       $v0, %hi(D_80156954)
/* D0C44 8013A544 8C426954 */  lw        $v0, %lo(D_80156954)($v0)
/* D0C48 8013A548 02022021 */  addu      $a0, $s0, $v0
/* D0C4C 8013A54C 8C820014 */  lw        $v0, 0x14($a0)
/* D0C50 8013A550 30420001 */  andi      $v0, $v0, 1
/* D0C54 8013A554 10400006 */  beqz      $v0, .L8013A570
/* D0C58 8013A558 26310001 */   addiu    $s1, $s1, 1
/* D0C5C 8013A55C 80820005 */  lb        $v0, 5($a0)
/* D0C60 8013A560 10520003 */  beq       $v0, $s2, .L8013A570
/* D0C64 8013A564 00000000 */   nop      
/* D0C68 8013A568 0C04EA4F */  jal       func_8013A93C
/* D0C6C 8013A56C 00000000 */   nop      
.L8013A570:
/* D0C70 8013A570 2A22005A */  slti      $v0, $s1, 0x5a
/* D0C74 8013A574 1440FFF2 */  bnez      $v0, .L8013A540
/* D0C78 8013A578 2610007C */   addiu    $s0, $s0, 0x7c
/* D0C7C 8013A57C 24110001 */  addiu     $s1, $zero, 1
/* D0C80 8013A580 3C128015 */  lui       $s2, %hi(D_80156954)
/* D0C84 8013A584 26526954 */  addiu     $s2, $s2, %lo(D_80156954)
/* D0C88 8013A588 2414000B */  addiu     $s4, $zero, 0xb
/* D0C8C 8013A58C 2413000C */  addiu     $s3, $zero, 0xc
/* D0C90 8013A590 2410007C */  addiu     $s0, $zero, 0x7c
.L8013A594:
/* D0C94 8013A594 8E420000 */  lw        $v0, ($s2)
/* D0C98 8013A598 02021821 */  addu      $v1, $s0, $v0
/* D0C9C 8013A59C 8C620014 */  lw        $v0, 0x14($v1)
/* D0CA0 8013A5A0 30420001 */  andi      $v0, $v0, 1
/* D0CA4 8013A5A4 5040000F */  beql      $v0, $zero, .L8013A5E4
/* D0CA8 8013A5A8 26310001 */   addiu    $s1, $s1, 1
/* D0CAC 8013A5AC 8C64005C */  lw        $a0, 0x5c($v1)
/* D0CB0 8013A5B0 5080000C */  beql      $a0, $zero, .L8013A5E4
/* D0CB4 8013A5B4 26310001 */   addiu    $s1, $s1, 1
/* D0CB8 8013A5B8 80620006 */  lb        $v0, 6($v1)
/* D0CBC 8013A5BC 10540009 */  beq       $v0, $s4, .L8013A5E4
/* D0CC0 8013A5C0 26310001 */   addiu    $s1, $s1, 1
/* D0CC4 8013A5C4 10530007 */  beq       $v0, $s3, .L8013A5E4
/* D0CC8 8013A5C8 00000000 */   nop      
/* D0CCC 8013A5CC 0C00AB1E */  jal       general_heap_free
/* D0CD0 8013A5D0 00000000 */   nop      
/* D0CD4 8013A5D4 8E420000 */  lw        $v0, ($s2)
/* D0CD8 8013A5D8 02021021 */  addu      $v0, $s0, $v0
/* D0CDC 8013A5DC AC40005C */  sw        $zero, 0x5c($v0)
/* D0CE0 8013A5E0 A4400060 */  sh        $zero, 0x60($v0)
.L8013A5E4:
/* D0CE4 8013A5E4 2A22005A */  slti      $v0, $s1, 0x5a
/* D0CE8 8013A5E8 1440FFEA */  bnez      $v0, .L8013A594
/* D0CEC 8013A5EC 2610007C */   addiu    $s0, $s0, 0x7c
/* D0CF0 8013A5F0 8FBF0024 */  lw        $ra, 0x24($sp)
/* D0CF4 8013A5F4 8FB40020 */  lw        $s4, 0x20($sp)
/* D0CF8 8013A5F8 8FB3001C */  lw        $s3, 0x1c($sp)
/* D0CFC 8013A5FC 8FB20018 */  lw        $s2, 0x18($sp)
/* D0D00 8013A600 8FB10014 */  lw        $s1, 0x14($sp)
/* D0D04 8013A604 8FB00010 */  lw        $s0, 0x10($sp)
/* D0D08 8013A608 03E00008 */  jr        $ra
/* D0D0C 8013A60C 27BD0028 */   addiu    $sp, $sp, 0x28
