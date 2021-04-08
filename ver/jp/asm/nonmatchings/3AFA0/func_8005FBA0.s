.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FBA0
/* 3AFA0 8005FBA0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 3AFA4 8005FBA4 AFB00020 */  sw        $s0, 0x20($sp)
/* 3AFA8 8005FBA8 0080802D */  daddu     $s0, $a0, $zero
/* 3AFAC 8005FBAC 24040301 */  addiu     $a0, $zero, 0x301
/* 3AFB0 8005FBB0 27A50010 */  addiu     $a1, $sp, 0x10
/* 3AFB4 8005FBB4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 3AFB8 8005FBB8 AFB10024 */  sw        $s1, 0x24($sp)
/* 3AFBC 8005FBBC 0C0180B2 */  jal       func_800602C8
/* 3AFC0 8005FBC0 A3B00010 */   sb       $s0, 0x10($sp)
/* 3AFC4 8005FBC4 24040001 */  addiu     $a0, $zero, 1
/* 3AFC8 8005FBC8 0C018244 */  jal       func_80060910
/* 3AFCC 8005FBCC 0040882D */   daddu    $s1, $v0, $zero
/* 3AFD0 8005FBD0 1620000A */  bnez      $s1, .L8005FBFC
/* 3AFD4 8005FBD4 0040202D */   daddu    $a0, $v0, $zero
/* 3AFD8 8005FBD8 00101080 */  sll       $v0, $s0, 2
/* 3AFDC 8005FBDC 00501021 */  addu      $v0, $v0, $s0
/* 3AFE0 8005FBE0 00021040 */  sll       $v0, $v0, 1
/* 3AFE4 8005FBE4 24030002 */  addiu     $v1, $zero, 2
/* 3AFE8 8005FBE8 3C01800B */  lui       $at, %hi(D_800B1D29)
/* 3AFEC 8005FBEC 00220821 */  addu      $at, $at, $v0
/* 3AFF0 8005FBF0 A0231D29 */  sb        $v1, %lo(D_800B1D29)($at)
/* 3AFF4 8005FBF4 08017F05 */  j         .L8005FC14
/* 3AFF8 8005FBF8 00000000 */   nop
.L8005FBFC:
/* 3AFFC 8005FBFC 00101080 */  sll       $v0, $s0, 2
/* 3B000 8005FC00 00501021 */  addu      $v0, $v0, $s0
/* 3B004 8005FC04 00021040 */  sll       $v0, $v0, 1
/* 3B008 8005FC08 3C01800B */  lui       $at, %hi(D_800B1D29)
/* 3B00C 8005FC0C 00220821 */  addu      $at, $at, $v0
/* 3B010 8005FC10 A0201D29 */  sb        $zero, %lo(D_800B1D29)($at)
.L8005FC14:
/* 3B014 8005FC14 0C018244 */  jal       func_80060910
/* 3B018 8005FC18 00000000 */   nop
/* 3B01C 8005FC1C 0220102D */  daddu     $v0, $s1, $zero
/* 3B020 8005FC20 8FBF0028 */  lw        $ra, 0x28($sp)
/* 3B024 8005FC24 8FB10024 */  lw        $s1, 0x24($sp)
/* 3B028 8005FC28 8FB00020 */  lw        $s0, 0x20($sp)
/* 3B02C 8005FC2C 03E00008 */  jr        $ra
/* 3B030 8005FC30 27BD0030 */   addiu    $sp, $sp, 0x30
/* 3B034 8005FC34 00000000 */  nop
/* 3B038 8005FC38 00000000 */  nop
/* 3B03C 8005FC3C 00000000 */  nop
