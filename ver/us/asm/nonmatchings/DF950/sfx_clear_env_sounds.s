.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sfx_clear_env_sounds
/* DFD70 80149670 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DFD74 80149674 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DFD78 80149678 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DFD7C 8014967C AFBF001C */  sw        $ra, 0x1c($sp)
/* DFD80 80149680 AFB20018 */  sw        $s2, 0x18($sp)
/* DFD84 80149684 AFB10014 */  sw        $s1, 0x14($sp)
/* DFD88 80149688 AFB00010 */  sw        $s0, 0x10($sp)
/* DFD8C 8014968C 80420070 */  lb        $v0, 0x70($v0)
/* DFD90 80149690 14400005 */  bnez      $v0, .L801496A8
/* DFD94 80149694 00000000 */   nop
/* DFD98 80149698 3C028016 */  lui       $v0, %hi(D_801598A0)
/* DFD9C 8014969C 244298A0 */  addiu     $v0, $v0, %lo(D_801598A0)
/* DFDA0 801496A0 080525AC */  j         .L801496B0
/* DFDA4 801496A4 00000000 */   nop
.L801496A8:
/* DFDA8 801496A8 3C028016 */  lui       $v0, %hi(D_801599B8)
/* DFDAC 801496AC 244299B8 */  addiu     $v0, $v0, %lo(D_801599B8)
.L801496B0:
/* DFDB0 801496B0 3C018016 */  lui       $at, %hi(D_80159AD0)
/* DFDB4 801496B4 AC229AD0 */  sw        $v0, %lo(D_80159AD0)($at)
/* DFDB8 801496B8 00041400 */  sll       $v0, $a0, 0x10
/* DFDBC 801496BC 10400013 */  beqz      $v0, .L8014970C
/* DFDC0 801496C0 0000902D */   daddu    $s2, $zero, $zero
/* DFDC4 801496C4 3C118016 */  lui       $s1, %hi(D_80159AD0)
/* DFDC8 801496C8 8E319AD0 */  lw        $s1, %lo(D_80159AD0)($s1)
/* DFDCC 801496CC 26300004 */  addiu     $s0, $s1, 4
.L801496D0:
/* DFDD0 801496D0 8E220000 */  lw        $v0, ($s1)
/* DFDD4 801496D4 30420001 */  andi      $v0, $v0, 1
/* DFDD8 801496D8 10400006 */  beqz      $v0, .L801496F4
/* DFDDC 801496DC 26520001 */   addiu    $s2, $s2, 1
/* DFDE0 801496E0 8E040000 */  lw        $a0, ($s0)
/* DFDE4 801496E4 92050008 */  lbu       $a1, 8($s0)
/* DFDE8 801496E8 92060009 */  lbu       $a2, 9($s0)
/* DFDEC 801496EC 0C015490 */  jal       snd_start_sound_with_shift
/* DFDF0 801496F0 8607000A */   lh       $a3, 0xa($s0)
.L801496F4:
/* DFDF4 801496F4 2610001C */  addiu     $s0, $s0, 0x1c
/* DFDF8 801496F8 2A42000A */  slti      $v0, $s2, 0xa
/* DFDFC 801496FC 1440FFF4 */  bnez      $v0, .L801496D0
/* DFE00 80149700 2631001C */   addiu    $s1, $s1, 0x1c
/* DFE04 80149704 080525C7 */  j         .L8014971C
/* DFE08 80149708 00000000 */   nop
.L8014970C:
/* DFE0C 8014970C 3C048016 */  lui       $a0, %hi(D_80159AD0)
/* DFE10 80149710 8C849AD0 */  lw        $a0, %lo(D_80159AD0)($a0)
/* DFE14 80149714 0C01925C */  jal       bzero
/* DFE18 80149718 24050118 */   addiu    $a1, $zero, 0x118
.L8014971C:
/* DFE1C 8014971C 8FBF001C */  lw        $ra, 0x1c($sp)
/* DFE20 80149720 8FB20018 */  lw        $s2, 0x18($sp)
/* DFE24 80149724 8FB10014 */  lw        $s1, 0x14($sp)
/* DFE28 80149728 8FB00010 */  lw        $s0, 0x10($sp)
/* DFE2C 8014972C 03E00008 */  jr        $ra
/* DFE30 80149730 27BD0020 */   addiu    $sp, $sp, 0x20
