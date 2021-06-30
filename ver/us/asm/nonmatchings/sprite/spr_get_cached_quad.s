.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_get_cached_quad
/* FEE7C 802DBD8C 3C02802E */  lui       $v0, %hi(D_802DFE48)
/* FEE80 802DBD90 2442FE48 */  addiu     $v0, $v0, %lo(D_802DFE48)
/* FEE84 802DBD94 00041880 */  sll       $v1, $a0, 2
/* FEE88 802DBD98 00621821 */  addu      $v1, $v1, $v0
/* FEE8C 802DBD9C 8C620000 */  lw        $v0, ($v1)
/* FEE90 802DBDA0 3442001F */  ori       $v0, $v0, 0x1f
/* FEE94 802DBDA4 AC620000 */  sw        $v0, ($v1)
/* FEE98 802DBDA8 3C02802E */  lui       $v0, %hi(D_802DFE44)
/* FEE9C 802DBDAC 8C42FE44 */  lw        $v0, %lo(D_802DFE44)($v0)
/* FEEA0 802DBDB0 00042180 */  sll       $a0, $a0, 6
/* FEEA4 802DBDB4 03E00008 */  jr        $ra
/* FEEA8 802DBDB8 00441021 */   addu     $v0, $v0, $a0
