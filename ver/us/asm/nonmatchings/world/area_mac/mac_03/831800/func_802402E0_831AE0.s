.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402E0_831AE0
/* 831AE0 802402E0 8C8200C0 */  lw        $v0, 0xc0($a0)
/* 831AE4 802402E4 284202D1 */  slti      $v0, $v0, 0x2d1
/* 831AE8 802402E8 50400001 */  beql      $v0, $zero, .L802402F0
/* 831AEC 802402EC AC8000C0 */   sw       $zero, 0xc0($a0)
.L802402F0:
/* 831AF0 802402F0 8C8300C0 */  lw        $v1, 0xc0($a0)
/* 831AF4 802402F4 00031040 */  sll       $v0, $v1, 1
/* 831AF8 802402F8 00431021 */  addu      $v0, $v0, $v1
/* 831AFC 802402FC 00021040 */  sll       $v0, $v0, 1
/* 831B00 80240300 AC820084 */  sw        $v0, 0x84($a0)
/* 831B04 80240304 000317C2 */  srl       $v0, $v1, 0x1f
/* 831B08 80240308 00621821 */  addu      $v1, $v1, $v0
/* 831B0C 8024030C 00031843 */  sra       $v1, $v1, 1
/* 831B10 80240310 24020002 */  addiu     $v0, $zero, 2
/* 831B14 80240314 03E00008 */  jr        $ra
/* 831B18 80240318 AC830088 */   sw       $v1, 0x88($a0)
/* 831B1C 8024031C 00000000 */  nop
