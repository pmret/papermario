.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_string_width
/* BCB74 80126474 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BCB78 80126478 30A5FFFF */  andi      $a1, $a1, 0xffff
/* BCB7C 8012647C AFA5001C */  sw        $a1, 0x1c($sp)
/* BCB80 80126480 0000282D */  daddu     $a1, $zero, $zero
/* BCB84 80126484 27A60020 */  addiu     $a2, $sp, 0x20
/* BCB88 80126488 00A0382D */  daddu     $a3, $a1, $zero
/* BCB8C 8012648C AFBF0028 */  sw        $ra, 0x28($sp)
/* BCB90 80126490 AFA00010 */  sw        $zero, 0x10($sp)
/* BCB94 80126494 AFA00014 */  sw        $zero, 0x14($sp)
/* BCB98 80126498 0C0497DA */  jal       get_string_properties
/* BCB9C 8012649C AFA00018 */   sw       $zero, 0x18($sp)
/* BCBA0 801264A0 8FA20020 */  lw        $v0, 0x20($sp)
/* BCBA4 801264A4 8FBF0028 */  lw        $ra, 0x28($sp)
/* BCBA8 801264A8 03E00008 */  jr        $ra
/* BCBAC 801264AC 27BD0030 */   addiu    $sp, $sp, 0x30
