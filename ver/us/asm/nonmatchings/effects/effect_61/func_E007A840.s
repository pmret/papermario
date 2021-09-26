.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007A840
/* 37CD80 E007A840 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 37CD84 E007A844 3C02E008 */  lui       $v0, %hi(func_E007A88C)
/* 37CD88 E007A848 2442A88C */  addiu     $v0, $v0, %lo(func_E007A88C)
/* 37CD8C E007A84C AFA2001C */  sw        $v0, 0x1c($sp)
/* 37CD90 E007A850 2402002D */  addiu     $v0, $zero, 0x2d
/* 37CD94 E007A854 AFA40018 */  sw        $a0, 0x18($sp)
/* 37CD98 E007A858 27A40010 */  addiu     $a0, $sp, 0x10
/* 37CD9C E007A85C AFBF0020 */  sw        $ra, 0x20($sp)
/* 37CDA0 E007A860 AFA00014 */  sw        $zero, 0x14($sp)
/* 37CDA4 E007A864 0C080120 */  jal       shim_queue_render_task
/* 37CDA8 E007A868 AFA20010 */   sw       $v0, 0x10($sp)
/* 37CDAC E007A86C 8C430000 */  lw        $v1, ($v0)
/* 37CDB0 E007A870 34630002 */  ori       $v1, $v1, 2
/* 37CDB4 E007A874 AC430000 */  sw        $v1, ($v0)
/* 37CDB8 E007A878 8FBF0020 */  lw        $ra, 0x20($sp)
/* 37CDBC E007A87C 03E00008 */  jr        $ra
/* 37CDC0 E007A880 27BD0028 */   addiu    $sp, $sp, 0x28
