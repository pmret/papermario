.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E0_DCD3B0
/* DCD3B0 802406E0 3C018011 */  lui       $at, %hi(gPlayerStatus+0x28)
/* DCD3B4 802406E4 C422EFF0 */  lwc1      $f2, %lo(gPlayerStatus+0x28)($at)
/* DCD3B8 802406E8 3C014454 */  lui       $at, 0x4454
/* DCD3BC 802406EC 34218000 */  ori       $at, $at, 0x8000
/* DCD3C0 802406F0 44810000 */  mtc1      $at, $f0
/* DCD3C4 802406F4 00000000 */  nop
/* DCD3C8 802406F8 4600103C */  c.lt.s    $f2, $f0
/* DCD3CC 802406FC 00000000 */  nop
/* DCD3D0 80240700 45010002 */  bc1t      .L8024070C
/* DCD3D4 80240704 0000102D */   daddu    $v0, $zero, $zero
/* DCD3D8 80240708 24020002 */  addiu     $v0, $zero, 2
.L8024070C:
/* DCD3DC 8024070C 03E00008 */  jr        $ra
/* DCD3E0 80240710 00000000 */   nop
/* DCD3E4 80240714 00000000 */  nop
/* DCD3E8 80240718 00000000 */  nop
/* DCD3EC 8024071C 00000000 */  nop
