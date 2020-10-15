.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_actor_current_position
/* 198504 80269C24 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 198508 80269C28 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 19850C 80269C2C 4485A000 */  mtc1      $a1, $f20
/* 198510 80269C30 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 198514 80269C34 4486B000 */  mtc1      $a2, $f22
/* 198518 80269C38 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 19851C 80269C3C 4487C000 */  mtc1      $a3, $f24
/* 198520 80269C40 AFBF0010 */  sw        $ra, 0x10($sp)
/* 198524 80269C44 0C09A75B */  jal       get_actor
/* 198528 80269C48 00000000 */   nop      
/* 19852C 80269C4C E4540144 */  swc1      $f20, 0x144($v0)
/* 198530 80269C50 E4560148 */  swc1      $f22, 0x148($v0)
/* 198534 80269C54 E458014C */  swc1      $f24, 0x14c($v0)
/* 198538 80269C58 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19853C 80269C5C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 198540 80269C60 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 198544 80269C64 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 198548 80269C68 03E00008 */  jr        $ra
/* 19854C 80269C6C 27BD0030 */   addiu    $sp, $sp, 0x30
