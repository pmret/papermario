.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240448_B141B8
/* B141B8 80240448 3C068024 */  lui       $a2, %hi(func_80240B00_900170)
/* B141BC 8024044C 8CC60B00 */  lw        $a2, %lo(func_80240B00_900170)($a2)
/* B141C0 80240450 18C00011 */  blez      $a2, .L80240498
/* B141C4 80240454 3C02FC12 */   lui      $v0, 0xfc12
/* B141C8 80240458 3C04800A */  lui       $a0, %hi(D_8009A66C)
/* B141CC 8024045C 2484A66C */  addiu     $a0, $a0, %lo(D_8009A66C)
/* B141D0 80240460 8C830000 */  lw        $v1, ($a0)
/* B141D4 80240464 34427E24 */  ori       $v0, $v0, 0x7e24
/* B141D8 80240468 0060282D */  daddu     $a1, $v1, $zero
/* B141DC 8024046C 24630008 */  addiu     $v1, $v1, 8
/* B141E0 80240470 AC830000 */  sw        $v1, ($a0)
/* B141E4 80240474 ACA20000 */  sw        $v0, ($a1)
/* B141E8 80240478 2402F7FB */  addiu     $v0, $zero, -0x805
/* B141EC 8024047C ACA20004 */  sw        $v0, 4($a1)
/* B141F0 80240480 24620008 */  addiu     $v0, $v1, 8
/* B141F4 80240484 AC820000 */  sw        $v0, ($a0)
/* B141F8 80240488 3C02FA00 */  lui       $v0, 0xfa00
/* B141FC 8024048C AC620000 */  sw        $v0, ($v1)
/* B14200 80240490 30C200FF */  andi      $v0, $a2, 0xff
/* B14204 80240494 AC620004 */  sw        $v0, 4($v1)
.L80240498:
/* B14208 80240498 03E00008 */  jr        $ra
/* B1420C 8024049C 00000000 */   nop      
