.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sfx_play_sound_looping
/* E0008 80149908 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E000C 8014990C 3C038016 */  lui       $v1, %hi(D_80159AD0)
/* E0010 80149910 8C639AD0 */  lw        $v1, %lo(D_80159AD0)($v1)
/* E0014 80149914 0000402D */  daddu     $t0, $zero, $zero
/* E0018 80149918 AFBF0010 */  sw        $ra, 0x10($sp)
.L8014991C:
/* E001C 8014991C 8C620000 */  lw        $v0, ($v1)
/* E0020 80149920 30420001 */  andi      $v0, $v0, 1
/* E0024 80149924 10400004 */  beqz      $v0, .L80149938
/* E0028 80149928 25080001 */   addiu    $t0, $t0, 1
/* E002C 8014992C 2902000A */  slti      $v0, $t0, 0xa
/* E0030 80149930 1440FFFA */  bnez      $v0, .L8014991C
/* E0034 80149934 2463001C */   addiu    $v1, $v1, 0x1c
.L80149938:
/* E0038 80149938 A467000E */  sh        $a3, 0xe($v1)
/* E003C 8014993C 00073C00 */  sll       $a3, $a3, 0x10
/* E0040 80149940 A065000C */  sb        $a1, 0xc($v1)
/* E0044 80149944 30A500FF */  andi      $a1, $a1, 0xff
/* E0048 80149948 A066000D */  sb        $a2, 0xd($v1)
/* E004C 8014994C 30C600FF */  andi      $a2, $a2, 0xff
/* E0050 80149950 8C620000 */  lw        $v0, ($v1)
/* E0054 80149954 00073C03 */  sra       $a3, $a3, 0x10
/* E0058 80149958 AC640004 */  sw        $a0, 4($v1)
/* E005C 8014995C 34420001 */  ori       $v0, $v0, 1
/* E0060 80149960 0C015490 */  jal       snd_start_sound_with_shift
/* E0064 80149964 AC620000 */   sw       $v0, ($v1)
/* E0068 80149968 8FBF0010 */  lw        $ra, 0x10($sp)
/* E006C 8014996C 03E00008 */  jr        $ra
/* E0070 80149970 27BD0018 */   addiu    $sp, $sp, 0x18
