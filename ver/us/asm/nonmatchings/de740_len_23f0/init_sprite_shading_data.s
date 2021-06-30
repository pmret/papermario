.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel init_sprite_shading_data
/* DE7F0 801480F0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DE7F4 801480F4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DE7F8 801480F8 80420070 */  lb        $v0, 0x70($v0)
/* DE7FC 801480FC 1440000B */  bnez      $v0, .L8014812C
/* DE800 80148100 00000000 */   nop
/* DE804 80148104 3C028016 */  lui       $v0, %hi(D_801595C0)
/* DE808 80148108 244295C0 */  addiu     $v0, $v0, %lo(D_801595C0)
/* DE80C 8014810C 3C018015 */  lui       $at, %hi(D_80151328)
/* DE810 80148110 AC221328 */  sw        $v0, %lo(D_80151328)($at)
/* DE814 80148114 3C028016 */  lui       $v0, %hi(D_80159720)
/* DE818 80148118 24429720 */  addiu     $v0, $v0, %lo(D_80159720)
/* DE81C 8014811C 3C018015 */  lui       $at, %hi(D_801512B0)
/* DE820 80148120 AC2212B0 */  sw        $v0, %lo(D_801512B0)($at)
/* DE824 80148124 03E00008 */  jr        $ra
/* DE828 80148128 00000000 */   nop
.L8014812C:
/* DE82C 8014812C 3C028016 */  lui       $v0, %hi(D_80159670)
/* DE830 80148130 24429670 */  addiu     $v0, $v0, %lo(D_80159670)
/* DE834 80148134 3C018015 */  lui       $at, %hi(D_80151328)
/* DE838 80148138 AC221328 */  sw        $v0, %lo(D_80151328)($at)
/* DE83C 8014813C 3C028016 */  lui       $v0, %hi(D_801597D0)
/* DE840 80148140 244297D0 */  addiu     $v0, $v0, %lo(D_801597D0)
/* DE844 80148144 3C018015 */  lui       $at, %hi(D_801512B0)
/* DE848 80148148 AC2212B0 */  sw        $v0, %lo(D_801512B0)($at)
/* DE84C 8014814C 03E00008 */  jr        $ra
/* DE850 80148150 00000000 */   nop
