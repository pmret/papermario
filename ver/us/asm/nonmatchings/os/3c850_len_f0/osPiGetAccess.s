.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPiGetAccess
/* 3C8A4 800614A4 3C028009 */  lui       $v0, %hi(__osPiAccessQueueEnabled)
/* 3C8A8 800614A8 8C423D90 */  lw        $v0, %lo(__osPiAccessQueueEnabled)($v0)
/* 3C8AC 800614AC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3C8B0 800614B0 1440000F */  bnez      $v0, .L800614F0
/* 3C8B4 800614B4 AFBF0018 */   sw       $ra, 0x18($sp)
/* 3C8B8 800614B8 24020001 */  addiu     $v0, $zero, 1
/* 3C8BC 800614BC 3C018009 */  lui       $at, %hi(__osPiAccessQueueEnabled)
/* 3C8C0 800614C0 AC223D90 */  sw        $v0, %lo(__osPiAccessQueueEnabled)($at)
/* 3C8C4 800614C4 3C04800B */  lui       $a0, %hi(gOsPiMessageQueue)
/* 3C8C8 800614C8 24844380 */  addiu     $a0, $a0, %lo(gOsPiMessageQueue)
/* 3C8CC 800614CC 3C05800B */  lui       $a1, %hi(D_800AF8B0)
/* 3C8D0 800614D0 24A5F8B0 */  addiu     $a1, $a1, %lo(D_800AF8B0)
/* 3C8D4 800614D4 0C019560 */  jal       osCreateMesgQueue
/* 3C8D8 800614D8 24060001 */   addiu    $a2, $zero, 1
/* 3C8DC 800614DC 3C04800B */  lui       $a0, %hi(gOsPiMessageQueue)
/* 3C8E0 800614E0 24844380 */  addiu     $a0, $a0, %lo(gOsPiMessageQueue)
/* 3C8E4 800614E4 00002821 */  addu      $a1, $zero, $zero
/* 3C8E8 800614E8 0C019608 */  jal       osSendMesg
/* 3C8EC 800614EC 00003021 */   addu     $a2, $zero, $zero
.L800614F0:
/* 3C8F0 800614F0 3C04800B */  lui       $a0, %hi(gOsPiMessageQueue)
/* 3C8F4 800614F4 24844380 */  addiu     $a0, $a0, %lo(gOsPiMessageQueue)
/* 3C8F8 800614F8 27A50010 */  addiu     $a1, $sp, 0x10
/* 3C8FC 800614FC 0C0195BC */  jal       osRecvMesg
/* 3C900 80061500 24060001 */   addiu    $a2, $zero, 1
/* 3C904 80061504 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3C908 80061508 03E00008 */  jr        $ra
/* 3C90C 8006150C 27BD0020 */   addiu    $sp, $sp, 0x20
