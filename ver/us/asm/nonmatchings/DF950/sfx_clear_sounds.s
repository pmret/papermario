.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sfx_clear_sounds
/* DFD18 80149618 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DFD1C 8014961C AFB00010 */  sw        $s0, 0x10($sp)
/* DFD20 80149620 3C108016 */  lui       $s0, %hi(D_801598A0)
/* DFD24 80149624 261098A0 */  addiu     $s0, $s0, %lo(D_801598A0)
/* DFD28 80149628 0200202D */  daddu     $a0, $s0, $zero
/* DFD2C 8014962C AFBF0014 */  sw        $ra, 0x14($sp)
/* DFD30 80149630 0C01925C */  jal       bzero
/* DFD34 80149634 24050118 */   addiu    $a1, $zero, 0x118
/* DFD38 80149638 3C048016 */  lui       $a0, %hi(D_801599B8)
/* DFD3C 8014963C 248499B8 */  addiu     $a0, $a0, %lo(D_801599B8)
/* DFD40 80149640 0C01925C */  jal       bzero
/* DFD44 80149644 24050118 */   addiu    $a1, $zero, 0x118
/* DFD48 80149648 3C018016 */  lui       $at, %hi(D_80159AD0)
/* DFD4C 8014964C AC309AD0 */  sw        $s0, %lo(D_80159AD0)($at)
/* DFD50 80149650 0C0525FF */  jal       func_801497FC
/* DFD54 80149654 0000202D */   daddu    $a0, $zero, $zero
/* DFD58 80149658 0C052580 */  jal       sfx_reset_door_sounds
/* DFD5C 8014965C 00000000 */   nop
/* DFD60 80149660 8FBF0014 */  lw        $ra, 0x14($sp)
/* DFD64 80149664 8FB00010 */  lw        $s0, 0x10($sp)
/* DFD68 80149668 03E00008 */  jr        $ra
/* DFD6C 8014966C 27BD0018 */   addiu    $sp, $sp, 0x18
