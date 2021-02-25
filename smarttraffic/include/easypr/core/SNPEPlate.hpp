#ifndef LRP_HANDLER_H_
#define LRP_HANDLER_H_

#include <string>
#include <opencv2/opencv.hpp>

#include "../snpe/include/zdl/DlSystem/DlError.hpp"
#include "../snpe/include/zdl/DlSystem/RuntimeList.hpp"
#include "../snpe/include/zdl/DlSystem/UserBufferMap.hpp"
#include "../snpe/include/zdl/DlSystem/UDLFunc.hpp"
#include "../snpe/include/zdl/DlSystem/IUserBuffer.hpp"
#include "../snpe/include/zdl/DlSystem/TensorShape.hpp"
#include "../snpe/include/zdl/DlSystem/ITensorFactory.hpp"

#include "../snpe/include/zdl/DlContainer/IDlContainer.hpp"

#include "../snpe/include/zdl/SNPE/SNPE.hpp"
#include "../snpe/include/zdl/SNPE/SNPEBuilder.hpp"
#include "../snpe/include/zdl/SNPE/SNPEFactory.hpp"

#include "../snpe/include/zdl/DiagLog/IDiagLog.hpp"

#define MODEL_PATH "model/lpr_quantized.dlc"

class SNPEPlate
{
public:
    bool init();
    int SnpeSearch();
    cv::Mat srcMat;
    std::vector<cv::Mat> roiMatVec;
    void setSrcMat(cv::Mat src) {
        this->srcMat = src;
    }
    void setConfidence(float value);

private:
    float mConfidenceThreshold;
    std::unique_ptr<zdl::SNPE::SNPE> snpe;
    std::unique_ptr<zdl::DlSystem::ITensor> input;

private:

    zdl::DlSystem::Runtime_t getRunTime();

    std::unique_ptr<zdl::SNPE::SNPE> initSnpe(std::unique_ptr<zdl::DlContainer::IDlContainer> & container, zdl::DlSystem::Runtime_t runtime);

    std::unique_ptr<zdl::DlSystem::ITensor>  initITensorInput(std::unique_ptr<zdl::SNPE::SNPE> &snpe);

    void loadITensorInputData(cv::Mat &image, std::unique_ptr<zdl::DlSystem::ITensor> &input);
};

#endif

