.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80048170
/* 23570 80048170 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 23574 80048174 00041040 */  sll       $v0, $a0, 1
/* 23578 80048178 00441021 */  addu      $v0, $v0, $a0
/* 2357C 8004817C 00021080 */  sll       $v0, $v0, 2
/* 23580 80048180 00441023 */  subu      $v0, $v0, $a0
/* 23584 80048184 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 23588 80048188 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 2358C 8004818C 00021100 */  sll       $v0, $v0, 4
/* 23590 80048190 AFBF0018 */  sw        $ra, 0x18($sp)
/* 23594 80048194 AFB10014 */  sw        $s1, 0x14($sp)
/* 23598 80048198 AFB00010 */  sw        $s0, 0x10($sp)
/* 2359C 8004819C 00628821 */  addu      $s1, $v1, $v0
/* 235A0 800481A0 2403F7FF */  addiu     $v1, $zero, -0x801
/* 235A4 800481A4 8E220000 */  lw        $v0, ($s1)
/* 235A8 800481A8 822400A8 */  lb        $a0, 0xa8($s1)
/* 235AC 800481AC 00431024 */  and       $v0, $v0, $v1
/* 235B0 800481B0 1480000E */  bnez      $a0, .L800481EC
/* 235B4 800481B4 AE220000 */   sw       $v0, ($s1)
/* 235B8 800481B8 3C048011 */  lui       $a0, %hi(D_80108A14)
/* 235BC 800481BC 24848A14 */  addiu     $a0, $a0, %lo(D_80108A14)
/* 235C0 800481C0 24020001 */  addiu     $v0, $zero, 1
/* 235C4 800481C4 0C050529 */  jal       create_icon
/* 235C8 800481C8 A22200A8 */   sb       $v0, 0xa8($s1)
/* 235CC 800481CC 0040802D */  daddu     $s0, $v0, $zero
/* 235D0 800481D0 0200202D */  daddu     $a0, $s0, $zero
/* 235D4 800481D4 0C051280 */  jal       set_icon_flags
/* 235D8 800481D8 24050002 */   addiu    $a1, $zero, 2
/* 235DC 800481DC 0200202D */  daddu     $a0, $s0, $zero
/* 235E0 800481E0 0C051280 */  jal       set_icon_flags
/* 235E4 800481E4 24050080 */   addiu    $a1, $zero, 0x80
/* 235E8 800481E8 AE3000AC */  sw        $s0, 0xac($s1)
.L800481EC:
/* 235EC 800481EC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 235F0 800481F0 8FB10014 */  lw        $s1, 0x14($sp)
/* 235F4 800481F4 8FB00010 */  lw        $s0, 0x10($sp)
/* 235F8 800481F8 03E00008 */  jr        $ra
/* 235FC 800481FC 27BD0020 */   addiu    $sp, $sp, 0x20
