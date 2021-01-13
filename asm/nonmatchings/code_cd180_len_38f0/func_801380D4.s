.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801380D4
/* CE7D4 801380D4 44850000 */  mtc1      $a1, $f0
/* CE7D8 801380D8 28820002 */  slti      $v0, $a0, 2
/* CE7DC 801380DC 10400008 */  beqz      $v0, .L80138100
/* CE7E0 801380E0 00000000 */   nop
/* CE7E4 801380E4 04800006 */  bltz      $a0, .L80138100
/* CE7E8 801380E8 00041040 */   sll      $v0, $a0, 1
/* CE7EC 801380EC 00441021 */  addu      $v0, $v0, $a0
/* CE7F0 801380F0 000210C0 */  sll       $v0, $v0, 3
/* CE7F4 801380F4 3C018016 */  lui       $at, %hi(D_8015C7A4)
/* CE7F8 801380F8 00220821 */  addu      $at, $at, $v0
/* CE7FC 801380FC E420C7A4 */  swc1      $f0, %lo(D_8015C7A4)($at)
.L80138100:
/* CE800 80138100 03E00008 */  jr        $ra
/* CE804 80138104 00000000 */   nop
