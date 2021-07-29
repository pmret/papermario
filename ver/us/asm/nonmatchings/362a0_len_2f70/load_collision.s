.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_collision
/* 36458 8005B058 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 3645C 8005B05C AFBF002C */  sw        $ra, 0x2c($sp)
/* 36460 8005B060 AFB60028 */  sw        $s6, 0x28($sp)
/* 36464 8005B064 AFB50024 */  sw        $s5, 0x24($sp)
/* 36468 8005B068 AFB40020 */  sw        $s4, 0x20($sp)
/* 3646C 8005B06C AFB3001C */  sw        $s3, 0x1c($sp)
/* 36470 8005B070 AFB20018 */  sw        $s2, 0x18($sp)
/* 36474 8005B074 AFB10014 */  sw        $s1, 0x14($sp)
/* 36478 8005B078 0C016BF0 */  jal       load_hit_asset
/* 3647C 8005B07C AFB00010 */   sw       $s0, 0x10($sp)
/* 36480 8005B080 3C13800B */  lui       $s3, %hi(gCollisionData)
/* 36484 8005B084 267342E0 */  addiu     $s3, $s3, %lo(gCollisionData)
/* 36488 8005B088 8662000C */  lh        $v0, 0xc($s3)
/* 3648C 8005B08C 3C11800A */  lui       $s1, %hi(D_800A4264)
/* 36490 8005B090 8E314264 */  lw        $s1, %lo(D_800A4264)($s1)
/* 36494 8005B094 1840001C */  blez      $v0, .L8005B108
/* 36498 8005B098 0000902D */   daddu    $s2, $zero, $zero
/* 3649C 8005B09C 2416FFFF */  addiu     $s6, $zero, -1
/* 364A0 8005B0A0 3C158000 */  lui       $s5, 0x8000
/* 364A4 8005B0A4 0240A02D */  daddu     $s4, $s2, $zero
.L8005B0A8:
/* 364A8 8005B0A8 8E620004 */  lw        $v0, 4($s3)
/* 364AC 8005B0AC 8E230000 */  lw        $v1, ($s1)
/* 364B0 8005B0B0 00542021 */  addu      $a0, $v0, $s4
/* 364B4 8005B0B4 AC830000 */  sw        $v1, ($a0)
/* 364B8 8005B0B8 96250004 */  lhu       $a1, 4($s1)
/* 364BC 8005B0BC 0060102D */  daddu     $v0, $v1, $zero
/* 364C0 8005B0C0 1056000B */  beq       $v0, $s6, .L8005B0F0
/* 364C4 8005B0C4 A4850008 */   sh       $a1, 8($a0)
/* 364C8 8005B0C8 00551024 */  and       $v0, $v0, $s5
/* 364CC 8005B0CC 10400008 */  beqz      $v0, .L8005B0F0
/* 364D0 8005B0D0 00052C00 */   sll      $a1, $a1, 0x10
/* 364D4 8005B0D4 00128400 */  sll       $s0, $s2, 0x10
/* 364D8 8005B0D8 00108403 */  sra       $s0, $s0, 0x10
/* 364DC 8005B0DC 0200202D */  daddu     $a0, $s0, $zero
/* 364E0 8005B0E0 0C016DE0 */  jal       parent_collider_to_model
/* 364E4 8005B0E4 00052C03 */   sra      $a1, $a1, 0x10
/* 364E8 8005B0E8 0C016E89 */  jal       update_collider_transform
/* 364EC 8005B0EC 0200202D */   daddu    $a0, $s0, $zero
.L8005B0F0:
/* 364F0 8005B0F0 2694001C */  addiu     $s4, $s4, 0x1c
/* 364F4 8005B0F4 26520001 */  addiu     $s2, $s2, 1
/* 364F8 8005B0F8 8662000C */  lh        $v0, 0xc($s3)
/* 364FC 8005B0FC 0242102A */  slt       $v0, $s2, $v0
/* 36500 8005B100 1440FFE9 */  bnez      $v0, .L8005B0A8
/* 36504 8005B104 26310008 */   addiu    $s1, $s1, 8
.L8005B108:
/* 36508 8005B108 3C13800E */  lui       $s3, %hi(D_800D91D0)
/* 3650C 8005B10C 267391D0 */  addiu     $s3, $s3, %lo(D_800D91D0)
/* 36510 8005B110 8662000C */  lh        $v0, 0xc($s3)
/* 36514 8005B114 3C11800A */  lui       $s1, %hi(D_800A4268)
/* 36518 8005B118 8E314268 */  lw        $s1, %lo(D_800A4268)($s1)
/* 3651C 8005B11C 1840000E */  blez      $v0, .L8005B158
/* 36520 8005B120 0000902D */   daddu    $s2, $zero, $zero
/* 36524 8005B124 0240282D */  daddu     $a1, $s2, $zero
.L8005B128:
/* 36528 8005B128 26520001 */  addiu     $s2, $s2, 1
/* 3652C 8005B12C 8E620004 */  lw        $v0, 4($s3)
/* 36530 8005B130 8E230000 */  lw        $v1, ($s1)
/* 36534 8005B134 00452021 */  addu      $a0, $v0, $a1
/* 36538 8005B138 AC830000 */  sw        $v1, ($a0)
/* 3653C 8005B13C 96220004 */  lhu       $v0, 4($s1)
/* 36540 8005B140 24A5001C */  addiu     $a1, $a1, 0x1c
/* 36544 8005B144 A4820008 */  sh        $v0, 8($a0)
/* 36548 8005B148 8662000C */  lh        $v0, 0xc($s3)
/* 3654C 8005B14C 0242102A */  slt       $v0, $s2, $v0
/* 36550 8005B150 1440FFF5 */  bnez      $v0, .L8005B128
/* 36554 8005B154 26310008 */   addiu    $s1, $s1, 8
.L8005B158:
/* 36558 8005B158 3C04800A */  lui       $a0, %hi(D_800A4264)
/* 3655C 8005B15C 8C844264 */  lw        $a0, %lo(D_800A4264)($a0)
/* 36560 8005B160 0C00AB1E */  jal       general_heap_free
/* 36564 8005B164 00000000 */   nop
/* 36568 8005B168 3C04800A */  lui       $a0, %hi(D_800A4268)
/* 3656C 8005B16C 8C844268 */  lw        $a0, %lo(D_800A4268)($a0)
/* 36570 8005B170 0C00AB1E */  jal       general_heap_free
/* 36574 8005B174 00000000 */   nop
/* 36578 8005B178 8FBF002C */  lw        $ra, 0x2c($sp)
/* 3657C 8005B17C 8FB60028 */  lw        $s6, 0x28($sp)
/* 36580 8005B180 8FB50024 */  lw        $s5, 0x24($sp)
/* 36584 8005B184 8FB40020 */  lw        $s4, 0x20($sp)
/* 36588 8005B188 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3658C 8005B18C 8FB20018 */  lw        $s2, 0x18($sp)
/* 36590 8005B190 8FB10014 */  lw        $s1, 0x14($sp)
/* 36594 8005B194 8FB00010 */  lw        $s0, 0x10($sp)
/* 36598 8005B198 03E00008 */  jr        $ra
/* 3659C 8005B19C 27BD0030 */   addiu    $sp, $sp, 0x30
