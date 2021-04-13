.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_collider_type_by_id
/* 371A8 8005BDA8 30824000 */  andi      $v0, $a0, 0x4000
/* 371AC 8005BDAC 14400008 */  bnez      $v0, .L8005BDD0
/* 371B0 8005BDB0 000410C0 */   sll      $v0, $a0, 3
/* 371B4 8005BDB4 00441023 */  subu      $v0, $v0, $a0
/* 371B8 8005BDB8 3C03800B */  lui       $v1, %hi(gCollisionData+0x4)
/* 371BC 8005BDBC 8C6342E4 */  lw        $v1, %lo(gCollisionData+0x4)($v1)
/* 371C0 8005BDC0 00021080 */  sll       $v0, $v0, 2
/* 371C4 8005BDC4 00431021 */  addu      $v0, $v0, $v1
/* 371C8 8005BDC8 03E00008 */  jr        $ra
/* 371CC 8005BDCC 8C420000 */   lw       $v0, ($v0)
.L8005BDD0:
/* 371D0 8005BDD0 03E00008 */  jr        $ra
/* 371D4 8005BDD4 0000102D */   daddu    $v0, $zero, $zero
