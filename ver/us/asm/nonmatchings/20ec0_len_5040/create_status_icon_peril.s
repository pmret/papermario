.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_status_icon_peril
/* 23464 80048064 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 23468 80048068 00041040 */  sll       $v0, $a0, 1
/* 2346C 8004806C 00441021 */  addu      $v0, $v0, $a0
/* 23470 80048070 00021080 */  sll       $v0, $v0, 2
/* 23474 80048074 00441023 */  subu      $v0, $v0, $a0
/* 23478 80048078 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 2347C 8004807C 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 23480 80048080 00021100 */  sll       $v0, $v0, 4
/* 23484 80048084 AFBF0018 */  sw        $ra, 0x18($sp)
/* 23488 80048088 AFB10014 */  sw        $s1, 0x14($sp)
/* 2348C 8004808C AFB00010 */  sw        $s0, 0x10($sp)
/* 23490 80048090 00628821 */  addu      $s1, $v1, $v0
/* 23494 80048094 2403FBFF */  addiu     $v1, $zero, -0x401
/* 23498 80048098 8E220000 */  lw        $v0, ($s1)
/* 2349C 8004809C 822400A0 */  lb        $a0, 0xa0($s1)
/* 234A0 800480A0 00431024 */  and       $v0, $v0, $v1
/* 234A4 800480A4 1480000E */  bnez      $a0, .L800480E0
/* 234A8 800480A8 AE220000 */   sw       $v0, ($s1)
/* 234AC 800480AC 3C048011 */  lui       $a0, %hi(D_801089C4)
/* 234B0 800480B0 248489C4 */  addiu     $a0, $a0, %lo(D_801089C4)
/* 234B4 800480B4 24020001 */  addiu     $v0, $zero, 1
/* 234B8 800480B8 0C050529 */  jal       create_hud_element
/* 234BC 800480BC A22200A0 */   sb       $v0, 0xa0($s1)
/* 234C0 800480C0 0040802D */  daddu     $s0, $v0, $zero
/* 234C4 800480C4 0200202D */  daddu     $a0, $s0, $zero
/* 234C8 800480C8 0C051280 */  jal       set_hud_element_flags
/* 234CC 800480CC 24050002 */   addiu    $a1, $zero, 2
/* 234D0 800480D0 0200202D */  daddu     $a0, $s0, $zero
/* 234D4 800480D4 0C051280 */  jal       set_hud_element_flags
/* 234D8 800480D8 24050080 */   addiu    $a1, $zero, 0x80
/* 234DC 800480DC AE3000A4 */  sw        $s0, 0xa4($s1)
.L800480E0:
/* 234E0 800480E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 234E4 800480E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 234E8 800480E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 234EC 800480EC 03E00008 */  jr        $ra
/* 234F0 800480F0 27BD0020 */   addiu    $sp, $sp, 0x20
