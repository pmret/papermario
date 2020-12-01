.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel remove_effect
/* 35850 8005A450 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 35854 8005A454 AFB10014 */  sw        $s1, 0x14($sp)
/* 35858 8005A458 0080882D */  daddu     $s1, $a0, $zero
/* 3585C 8005A45C AFB00010 */  sw        $s0, 0x10($sp)
/* 35860 8005A460 0000802D */  daddu     $s0, $zero, $zero
/* 35864 8005A464 3C03800B */  lui       $v1, %hi(D_800B4398)
/* 35868 8005A468 24634398 */  addiu     $v1, $v1, %lo(D_800B4398)
/* 3586C 8005A46C AFBF0018 */  sw        $ra, 0x18($sp)
.L8005A470:
/* 35870 8005A470 8C620000 */  lw        $v0, ($v1)
/* 35874 8005A474 10510006 */  beq       $v0, $s1, .L8005A490
/* 35878 8005A478 2A020060 */   slti     $v0, $s0, 0x60
/* 3587C 8005A47C 26100001 */  addiu     $s0, $s0, 1
/* 35880 8005A480 2A020060 */  slti      $v0, $s0, 0x60
/* 35884 8005A484 1440FFFA */  bnez      $v0, .L8005A470
/* 35888 8005A488 24630004 */   addiu    $v1, $v1, 4
/* 3588C 8005A48C 2A020060 */  slti      $v0, $s0, 0x60
.L8005A490:
/* 35890 8005A490 14400003 */  bnez      $v0, .L8005A4A0
/* 35894 8005A494 00000000 */   nop      
.L8005A498:
/* 35898 8005A498 08016926 */  j         .L8005A498
/* 3589C 8005A49C 00000000 */   nop      
.L8005A4A0:
/* 358A0 8005A4A0 8E24000C */  lw        $a0, 0xc($s1)
/* 358A4 8005A4A4 10800003 */  beqz      $a0, .L8005A4B4
/* 358A8 8005A4A8 00000000 */   nop      
/* 358AC 8005A4AC 0C00AB1E */  jal       general_heap_free
/* 358B0 8005A4B0 00000000 */   nop      
.L8005A4B4:
/* 358B4 8005A4B4 0C00AB1E */  jal       general_heap_free
/* 358B8 8005A4B8 0220202D */   daddu    $a0, $s1, $zero
/* 358BC 8005A4BC 00101080 */  sll       $v0, $s0, 2
/* 358C0 8005A4C0 3C01800B */  lui       $at, %hi(D_800B4398)
/* 358C4 8005A4C4 00220821 */  addu      $at, $at, $v0
/* 358C8 8005A4C8 AC204398 */  sw        $zero, %lo(D_800B4398)($at)
/* 358CC 8005A4CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 358D0 8005A4D0 8FB10014 */  lw        $s1, 0x14($sp)
/* 358D4 8005A4D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 358D8 8005A4D8 03E00008 */  jr        $ra
/* 358DC 8005A4DC 27BD0020 */   addiu    $sp, $sp, 0x20
