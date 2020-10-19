.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241328
/* A653B8 80241328 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A653BC 8024132C AFBF0020 */  sw        $ra, 0x20($sp)
/* A653C0 80241330 8C820148 */  lw        $v0, 0x148($a0)
/* A653C4 80241334 0C00EABB */  jal       get_npc_unsafe
/* A653C8 80241338 84440008 */   lh       $a0, 8($v0)
/* A653CC 8024133C 240300FF */  addiu     $v1, $zero, 0xff
/* A653D0 80241340 0000282D */  daddu     $a1, $zero, $zero
/* A653D4 80241344 00A0302D */  daddu     $a2, $a1, $zero
/* A653D8 80241348 A04300AC */  sb        $v1, 0xac($v0)
/* A653DC 8024134C AFA00010 */  sw        $zero, 0x10($sp)
/* A653E0 80241350 AFA00014 */  sw        $zero, 0x14($sp)
/* A653E4 80241354 AFA00018 */  sw        $zero, 0x18($sp)
/* A653E8 80241358 8C440024 */  lw        $a0, 0x24($v0)
/* A653EC 8024135C 0C0B7A25 */  jal       func_802DE894
/* A653F0 80241360 00A0382D */   daddu    $a3, $a1, $zero
/* A653F4 80241364 8FBF0020 */  lw        $ra, 0x20($sp)
/* A653F8 80241368 24020002 */  addiu     $v0, $zero, 2
/* A653FC 8024136C 03E00008 */  jr        $ra
/* A65400 80241370 27BD0028 */   addiu    $sp, $sp, 0x28
