.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A10
/* BCF600 80240A10 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BCF604 80240A14 AFB10014 */  sw        $s1, 0x14($sp)
/* BCF608 80240A18 0080882D */  daddu     $s1, $a0, $zero
/* BCF60C 80240A1C AFB20018 */  sw        $s2, 0x18($sp)
/* BCF610 80240A20 00A0902D */  daddu     $s2, $a1, $zero
/* BCF614 80240A24 AFB3001C */  sw        $s3, 0x1c($sp)
/* BCF618 80240A28 00C0982D */  daddu     $s3, $a2, $zero
/* BCF61C 80240A2C AFB00010 */  sw        $s0, 0x10($sp)
/* BCF620 80240A30 AFBF0020 */  sw        $ra, 0x20($sp)
/* BCF624 80240A34 0C090150 */  jal       func_80240540
/* BCF628 80240A38 00E0802D */   daddu    $s0, $a3, $zero
/* BCF62C 80240A3C 0220202D */  daddu     $a0, $s1, $zero
/* BCF630 80240A40 0240282D */  daddu     $a1, $s2, $zero
/* BCF634 80240A44 0260302D */  daddu     $a2, $s3, $zero
/* BCF638 80240A48 0C090159 */  jal       func_80240564
/* BCF63C 80240A4C AC500000 */   sw       $s0, ($v0)
/* BCF640 80240A50 8FBF0020 */  lw        $ra, 0x20($sp)
/* BCF644 80240A54 8FB3001C */  lw        $s3, 0x1c($sp)
/* BCF648 80240A58 8FB20018 */  lw        $s2, 0x18($sp)
/* BCF64C 80240A5C 8FB10014 */  lw        $s1, 0x14($sp)
/* BCF650 80240A60 8FB00010 */  lw        $s0, 0x10($sp)
/* BCF654 80240A64 03E00008 */  jr        $ra
/* BCF658 80240A68 27BD0028 */   addiu    $sp, $sp, 0x28
