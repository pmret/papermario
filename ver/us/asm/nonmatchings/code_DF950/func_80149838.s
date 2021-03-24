.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80149838
/* DFF38 80149838 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DFF3C 8014983C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DFF40 80149840 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DFF44 80149844 AFBF0018 */  sw        $ra, 0x18($sp)
/* DFF48 80149848 AFB10014 */  sw        $s1, 0x14($sp)
/* DFF4C 8014984C AFB00010 */  sw        $s0, 0x10($sp)
/* DFF50 80149850 80420070 */  lb        $v0, 0x70($v0)
/* DFF54 80149854 14400005 */  bnez      $v0, .L8014986C
/* DFF58 80149858 00000000 */   nop
/* DFF5C 8014985C 3C028016 */  lui       $v0, %hi(D_801598A0)
/* DFF60 80149860 244298A0 */  addiu     $v0, $v0, %lo(D_801598A0)
/* DFF64 80149864 0805261D */  j         .L80149874
/* DFF68 80149868 00000000 */   nop
.L8014986C:
/* DFF6C 8014986C 3C028016 */  lui       $v0, %hi(D_801599B8)
/* DFF70 80149870 244299B8 */  addiu     $v0, $v0, %lo(D_801599B8)
.L80149874:
/* DFF74 80149874 3C018016 */  lui       $at, %hi(D_80159AD0)
/* DFF78 80149878 AC229AD0 */  sw        $v0, %lo(D_80159AD0)($at)
/* DFF7C 8014987C 3C108016 */  lui       $s0, %hi(D_80159AD0)
/* DFF80 80149880 8E109AD0 */  lw        $s0, %lo(D_80159AD0)($s0)
/* DFF84 80149884 0000882D */  daddu     $s1, $zero, $zero
.L80149888:
/* DFF88 80149888 8E020000 */  lw        $v0, ($s0)
/* DFF8C 8014988C 30420001 */  andi      $v0, $v0, 1
/* DFF90 80149890 10400004 */  beqz      $v0, .L801498A4
/* DFF94 80149894 26310001 */   addiu    $s1, $s1, 1
/* DFF98 80149898 8E040004 */  lw        $a0, 4($s0)
/* DFF9C 8014989C 0C0154F0 */  jal       snd_stop_sound
/* DFFA0 801498A0 00000000 */   nop
.L801498A4:
/* DFFA4 801498A4 2A22000A */  slti      $v0, $s1, 0xa
/* DFFA8 801498A8 1440FFF7 */  bnez      $v0, .L80149888
/* DFFAC 801498AC 2610001C */   addiu    $s0, $s0, 0x1c
/* DFFB0 801498B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* DFFB4 801498B4 8FB10014 */  lw        $s1, 0x14($sp)
/* DFFB8 801498B8 8FB00010 */  lw        $s0, 0x10($sp)
/* DFFBC 801498BC 03E00008 */  jr        $ra
/* DFFC0 801498C0 27BD0020 */   addiu    $sp, $sp, 0x20
