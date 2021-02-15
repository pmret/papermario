.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243C10_C439C0
/* C439C0 80243C10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C439C4 80243C14 AFBF0010 */  sw        $ra, 0x10($sp)
/* C439C8 80243C18 0C00FB5A */  jal       get_enemy_safe
/* C439CC 80243C1C 24040009 */   addiu    $a0, $zero, 9
/* C439D0 80243C20 10400008 */  beqz      $v0, .L80243C44
/* C439D4 80243C24 24020002 */   addiu    $v0, $zero, 2
/* C439D8 80243C28 0C00FB3A */  jal       get_enemy
/* C439DC 80243C2C 24040009 */   addiu    $a0, $zero, 9
/* C439E0 80243C30 0040202D */  daddu     $a0, $v0, $zero
/* C439E4 80243C34 8C8300B0 */  lw        $v1, 0xb0($a0)
/* C439E8 80243C38 24020002 */  addiu     $v0, $zero, 2
/* C439EC 80243C3C 34630080 */  ori       $v1, $v1, 0x80
/* C439F0 80243C40 AC8300B0 */  sw        $v1, 0xb0($a0)
.L80243C44:
/* C439F4 80243C44 8FBF0010 */  lw        $ra, 0x10($sp)
/* C439F8 80243C48 03E00008 */  jr        $ra
/* C439FC 80243C4C 27BD0018 */   addiu    $sp, $sp, 0x18
